#include <iostream>
#include <vector>
#include <random>

const int X_DIMENSION = 10;
const int Y_DIMENSION = 10;

enum class Team {
  Vampire,
  Werewolf
};

class Entity {
 public:
  Entity(int x, int y, Team team) : x_(x), y_(y), team_(team) {}
  virtual ~Entity() = default;

  int x() const { return x_; }
  int y() const { return y_; }
  Team team() const { return team_; }

  virtual void Move() {
    std::uniform_int_distribution<int> distribution(-1, 1);
    x_ += distribution(generator_);
    y_ += distribution(generator_);
    // Make sure the entity stays within the map boundaries
    x_ = std::max(0, std::min(x_, X_DIMENSION - 1));
    y_ = std::max(0, std::min(y_, Y_DIMENSION - 1));
  }

  // Returns true if the entity attacks, false if it tries to move away
  virtual bool Attack(const Entity& other) {
    return power_level_ >= other.power_level_;
  }

  // Returns true if the entity gives medical aid, false if it does not
  virtual bool GiveMedicalAid(Entity& other) {
    return medic_ > 0 && other.health_ < 3;
  }

  void TakeDamage(int damage) {
    health_ -= damage;
    if (health_ <= 0) {
      // Entity has been killed, remove it from the map
      x_ = -1;
      y_ = -1;
    }
  }

  void Heal(int amount) {
    health_ += amount;
  }

 protected:
  int x_;
  int y_;
  Team team_;
  int power_level_;
  int defense_level_;
  int medic_;
  int health_;

 private:
  static std::mt19937 generator_;
};

std::mt19937 Entity::generator_;

class Vampire : public Entity {
 public:
  Vampire(int x, int y) : Entity(x, y, Team::Vampire) {
    power_level_ = std::uniform_int_distribution<int>(1, 3)(generator_);
    defense_level_ = std::uniform_int_distribution<int>(1, 2)(generator_);
    medic_ = std::uniform_int_distribution<int>(0, 2)(generator_);
    health_ = 3;
  }

  void Move() override {
    Entity::Move();
    // Vampires can also move diagonally
    std::uniform_int_distribution<int> distribution(-1, 1);
    x_ += distribution(generator_);
    y_ += distribution(generator_);
    // Make sure the vampire stays within the map boundaries
    x_ = std::max(0, std::min(x_, X_DIMENSION - 1));
   
y_ = std::max(0, std::min(y_, Y_DIMENSION - 1));
}
};

class Werewolf : public Entity {
public:
Werewolf(int x, int y) : Entity(x, y, Team::Werewolf) {
power_level_ = std::uniform_int_distribution<int>(1, 3)(generator_);
defense_level_ = std::uniform_int_distribution<int>(1, 2)(generator_);
medic_ = std::uniform_int_distribution<int>(0, 2)(generator_);
health_ = 3;
}
};

class Avatar {
public:
Avatar(int x, int y, Team team) : x_(x), y_(y), team_(team), magic_potions_(1) {}

int x() const { return x_; }
int y() const { return y_; }
Team team() const { return team_; }
int magic_potions() const { return magic_potions_; }

void Move(int dx, int dy) {
x_ += dx;
y_ += dy;
// Make sure the avatar stays within the map boundaries
x_ = std::max(0, std::min(x_, X_DIMENSION - 1));
y_ = std::max(0, std::min(y_, Y_DIMENSION - 1));
}

void HealAll(std::vector<Entity>& entities) {
if (magic_potions_ > 0) {
for (auto& entity : entities) {
if (entity.team() == team_) {
entity.Heal(1);
}
}
--magic_potions_;
}
}

void PickUpMagicPotion(int x, int y) {
if (x == x_ && y == y_) {
++magic_potions_;
}
}

private:
int x_;
int y_;
Team team_;
int magic_potions_;
};

int main() {
std::vector<Entity> entities;
// Initialize the entities randomly on the map
std::uniform_int_distribution<int> distribution(0, X_DIMENSION - 1);
for (int i = 0; i < X_DIMENSION * Y_DIMENSION / 15; ++i) {
int x = distribution(generator_);
int y = distribution(generator_);
if (i % 2 == 0) {
entities.emplace_back(Vampire(x, y));
} else {
entities.emplace_back(Werewolf(x, y));
}
}

// Initialize the avatar in the center of the map
Avatar avatar(X_DIMENSION / 2, Y_DIMENSION / 2, Team::Vampire);

while (true) {
// Check for game over conditions
int num_vampires = 0;
int num_werewolves = 0;
for (const auto& entity : entities) {
if (entity.team() == Team::Vampire) {
++num_vampires;
} else {
++num_werewolves;
}
}
if (num_vampires == 0 || num_werewolves == 0) {
std::cout << "Game over!" << std::endl;
break;
}
// Get player input
char input;
std::cin >> input;
switch (input) {
  case 'w':
    avatar.Move(0, -1);
    break;
  case 'a':
    avatar.Move(-1, 0);
    break;
  case 's':
    avatar.Move(0, 1);
    break;
  case 'd':
    avatar.Move(1, 0);
    break;
  case 'h':
    avatar.HealAll(entities);
    break;
  case 'p':
    std::cout << "Number of active vampires: " << num_vampires << std::endl;
    std::cout << "Number of active werewolves: " << num_werewolves << std::endl;
    std::cout << "Number of magic potions: " << avatar.magic_potions() << std::endl;
    break;
}

// Move the entities and handle interactions
for (auto& entity : entities) {
  entity.Move();
  for (auto& other : entities) {
    if (&entity == &other) {
      continue;
    }
    if (entity.x() == other.x() && entity.y() == other.y()) {
      // The entities are in the same location
      if (entity.team() == other.team()) {
        if (entity.GiveMedicalAid(other)) {
          --entity.medic_;
          other.Heal(1);
        }
      } else {
        if (entity.Attack(other)) {
          other.TakeDamage(entity.power_level_ - other.defense_level_);
        } else {
          entity.Move();
        }
      }
    }
  }
}

// Check if the avatar picked up a magic potion
avatar.PickUpMagicPotion(avatar.x(), avatar.y());

// Alternate between day and night
static bool is_day = true;
is_day = !is_day;
}

return 0;
}