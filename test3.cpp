#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// The ancestor class for all entities in the game
class Entity {
public:
  Entity(int x, int y) : x_(x), y_(y) {}

  // Get the x coordinate of the entity
  int getX() const { return x_; }
  // Get the y coordinate of the entity
  int getY() const { return y_; }
  // Set the x coordinate of the entity
  void setX(int x) { x_ = x; }
  // Set the y coordinate of the entity
  void setY(int y) { y_ = y; }
  // Get the health of the entity
  int getHealth() const { return health_; }
  // Set the health of the entity
  void setHealth(int health) { health_ = health; }
  // Get the power level of the entity
  int getPower() const { return power_; }
  // Get the defense level of the entity
  int getDefense() const { return defense_; }
  // Get the number of medics the entity has
  int getMedics() const { return medics_; }

private:
  int x_;
  int y_;
  int health_;
  int power_;
  int defense_;
  int medics_;
};

// The class for the avatar of the player
class Avatar : public Entity {
public:
  Avatar(int x, int y) : Entity(x, y) {}
};

// The class for the vampires in the game
class Vampire : public Entity {
public:
  Vampire(int x, int y) : Entity(x, y) {}
};

// The class for the werewolves in the game
class Werewolf : public Entity {
public:
  Werewolf(int x, int y) : Entity(x, y) {}
};

// The class for the game world
class World {
public:
  World(int x, int y) : x_(x), y_(y) {
    // Initialize the map with empty spaces
    map_.resize(y_, std::vector<char>(x_, ' '));
  }

  // Add an entity to the map
  void addEntity(Entity* entity) {
    map_[entity->getY()][entity->getX()] = entity->getSymbol();
    entities_.push_back(entity);
  }

  // Remove an entity from the map
  void removeEntity(Entity* entity) {
    map_[entity->getY()][entity->getX()] = ' ';
    entities_.erase(std::remove(entities_.begin(), entities_.end(), entity), entities_.end());
    delete entity;
  }

  // Get the symbol at a specific location on the map
  char getMapSymbol(int x, int y) const {
    return map_[y][x];
  }

  // Set the symbol at a specific location on the map
  void setMapSymbol(int x, int y, char symbol) {
    map_[y][x] = symbol;
  }

// Get the number of vampires in the game
int getVampireCount() const {
return std::count_if(entities_.begin(), entities_.end(), [](const Entity* e) { return dynamic_cast<const Vampire*>(e) != nullptr; });
}

// Get the number of werewolves in the game
int getWerewolfCount() const {
return std::count_if(entities_.begin(), entities_.end(), [](const Entity* e) { return dynamic_cast<const Werewolf*>(e) != nullptr; });
}

// Get the avatar of the player
Avatar* getAvatar() const {
return avatar_;
}

// Set the avatar of the player
void setAvatar(Avatar* avatar) {
avatar_ = avatar;
}

// Get the number of magic potions the player has
int getMagicPotionCount() const {
return magicPotionCount_;
}

// Set the number of magic potions the player has
void setMagicPotionCount(int magicPotionCount) {
magicPotionCount_ = magicPotionCount;
}

// Get the current season (day or night)
Season getSeason() const {
return season_;
}

// Set the current season (day or night)
void setSeason(Season season) {
season_ = season;
}

// Move the entities in the game
void moveEntities() {
// Random number generator for choosing movement direction
std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> directionDist(0, 3);
// Random number generator for choosing whether to attack or not
std::uniform_int_distribution<int> attackDist(0, 1);

for (Entity* entity : entities_) {
  // Choose a random direction to move in
  int direction = directionDist(rng);

  // Get the entity's current position
  int x = entity->getX();
  int y = entity->getY();

  // Move the entity in the chosen direction
  if (direction == 0) {
    x--;
  } else if (direction == 1) {
    x++;
  } else if (direction == 2) {
    y--;
  } else if (direction == 3) {
    y++;
  }

  // Check if the entity is moving out of bounds
  if (x < 0 || x >= x_ || y < 0 || y >= y_) {
    continue;
  }

  // Check if the entity is moving into water or a tree
  if (getMapSymbol(x, y) == 'W' || getMapSymbol(x, y) == 'T') {
    continue;
  }

  // Check if there is another entity at the destination
  Entity* otherEntity = nullptr;
  for (Entity* e : entities_) {
    if (e->getX() == x && e->getY() == y) {
      otherEntity = e;
      break;
    }
  }

  // If there is another entity at the destination
  if (otherEntity) {
    // If the two entities are from the same eam and the entity does not have full health, try to use a medic
if (dynamic_cast<Vampire*>(entity) && dynamic_cast<Vampire*>(otherEntity) && entity->getHealth() < 3) {
if (otherEntity->getMedics() > 0 && attackDist(rng) == 1) {
entity->setHealth(std::min(3, entity->getHealth() + 1));
otherEntity->setMedics(otherEntity->getMedics() - 1);
}
} else if (dynamic_cast<Werewolf*>(entity) && dynamic_cast<Werewolf*>(otherEntity) && entity->getHealth() < 3) {
if (otherEntity->getMedics() > 0 && attackDist(rng) == 1) {
entity->setHealth(std::min(3, entity->getHealth() + 1));
otherEntity->setMedics(otherEntity->getMedics() - 1);
}
} else {
// If the two entities are rivals, try to attack
if (entity->getPower() >= otherEntity->getDefense() && attackDist(rng) == 1) {
otherEntity->setHealth(std::max(0, otherEntity->getHealth() - (entity->getPower() - otherEntity->getDefense())));
if (otherEntity->getHealth() == 0) {
removeEntity(otherEntity);
}
}
}
} else {
// If there is no other entity at the destination, move the entity
entity->setX(x);
entity->setY(y);
}
}
}

// Check if the game is over
bool isGameOver() const {
return getVampireCount() == 0 || getWerewolfCount() == 0;
}

// Print the map to the console
void printMap() const {
for (int y = 0; y < y_; y++) {
for (int x = 0; x < x_; x++) {
std::cout << map_[y][x];
}
std::cout << std::endl;
}
}

private:
int x_;
int y_;
Avatar* avatar_;
int magicPotionCount_;
Season season_;
std::vector<std::vector<char>> map_;
std::vector<Entity*> entities_;
};

int main() {
// Create the game world with a 10x10 map
World world(10, 10);

// Add the avatar of the player to the map
Avatar* avatar = new Avatar(5, 5);
world.addEntity(avatar);
world.setAvatar(avatar);

// Add 7 vampires and 7 werewolves to the map
for (int i = 0; i < 7; i++) {
Vampire* vampire = new Vampire(i, i);
Werewolf* werewolf = new Werewolf(9 - i, 9 - i);
world.addEntity(vampire);
world.addEntity(werewolf);
}

// Set the initial number of magic potions to 1
world.setMagicPotionCount(1);

// Set the initial season to day
world.setSeason(Season::Day);

// Main game loop
while (true) {
// Print the map to the console
world.printMap();

// Check if the game is over
if (world.isGameOver()) {
  std::cout << "Game over!" << std::endl;
  break;
}

// Get user input
std::cout << "Enter a command (h for help):" << std::endl;
char input;
std::cin >> input;

if (input == 'q') {
  // Quit the game
  break;
} else if (input == 'p') {
  // Pause the game and display information
  std::cout << "Number of active vampires: " << world.getVampireCount() << std::endl;
  std::cout << "Number of active werewolves: " << world.getWerewolfCount() << std::endl;
  std::cout << "Number of magic potions: " << world.getMagicPotionCount() << std::endl;
  continue;
} else if (input == 'w') {
  // Move the avatar up
  if (avatar->getY() > 0 && world.getMapSymbol(avatar->getX(), avatar->getY() - 1) != 'W' && world.getMapSymbol(avatar->getX(), avatar->getY() - 1) != 'T') {
    avatar->setY(avatar->getY() - 1);
  }
} else if (input == 's') {
  // Move the avatar down
  if (avatar->getY() < world.getY() - 1 && world.getMapSymbol(avatar->getX(), avatar->getY() + 1) != 'W' && world.getMapSymbol(avatar->getX(), avatar->getY() + 1) != 'T') {
    avatar->setY(avatar->getY() + 1);
  }
} else if (input == 'a') {
  // Move the avatar left
  if (avatar->getX() > 0 && world.getMapSymbol(avatar->getX() - 1, avatar->getY()) != 'W' && world.getMapSymbol(avatar->getX() - 1, avatar->getY()) != 'T') {
    avatar->setX(avatar->getX() - 1);
  }
} else if (input == 'd') {
  // Move the avatar right
  if (avatar->getX() < world.getX() - 1 && world.getMapSymbol(avatar->getX() + 1, avatar->getY()) != 'W' && world.getMapSymbol(avatar->getX() + 1, avatar->getY()) != 'T') {
    avatar->setX(avatar->getX() + 1);
  }
} else if (input == 'h') {
  // Display help message
  std::cout << "Commands:" << std::endl;
  std::cout << "w: move up" << std::endl;
  std::cout << "s: move down" << std::endl;
  std::cout << "a: move left" << std::endl;
  std::cout << "d: move right" << std::endl;
  std::cout << "h: display this help message" << std::endl;
  std::cout << "p: pause the game and display information" << std::endl;
  std::cout << "q: quit the game" << std::endl;
} else {
std::cout << "Invalid command" << std::endl;
continue;
}
// Check if the avatar has picked up a magic potion
if (world.getMapSymbol(avatar->getX(), avatar->getY()) == 'P') {
  world.setMagicPotionCount(world.getMagicPotionCount() + 1);
  world.setMapSymbol(avatar->getX(), avatar->getY(), ' ');
}

// Check if the avatar is in the correct season to use a magic potion
if (input == 'h' && ((world.getSeason() == Season::Day && avatar->getTeam() == Team::Vampires) || (world.getSeason() == Season::Night && avatar->getTeam() == Team::Werewolves))) {
  // Use a magic potion to heal all party members
  if (world.getMagicPotionCount() > 0) {
    for (Entity* entity : world.getEntities()) {
      if (entity->getTeam() == avatar->getTeam()) {
        entity->setHealth(std::min(3, entity->getHealth() + 1));
      }
    }
    world.setMagicPotionCount(world.getMagicPotionCount() - 1);
  } else {
    std::cout << "You don't have any magic potions left!" << std::endl;
  }
}

// Move the entities in the game
world.moveEntities();

// Toggle the season
if (world.getSeason() == Season::Day) {
  world.setSeason(Season::Night);
} else {
  world.setSeason(Season::Day);
}
}

return 0;
}
