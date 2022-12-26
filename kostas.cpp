#include "libraries.h"
using namespace std;


//class avatar
class Avatar {
public:
    int x,y,i,j,health,power,filter,defence;
    char** map;
    char** gamemap;

    int Start(){
        srand((int)time(0));
        
        filter=rand()%2;
        power=(rand()%2)+1;
        health=5;
        defence=(rand()%1)+1;
    }

    int move(){   
        // Get user input (W-A-S-D) 
        cout << "Use W-S-A-D to move " <<endl;
        char input;
        cin >> input;
        if (input == 'w' || input == 'W') {
            // Move the avatar up
            if(map[i+1][j]=='e'&& gamemap[i+1][j]!='o')
                gamemap[i+1][j];
        }
        else if (input == 's'|| input == 'S') {
            // Move the avatar down
            if(map[i-1][j]=='e'&& gamemap[i-1][j]!='o')
                gamemap[i-1][j];
        }
        else if (input == 'a'|| input == 'A') {
            // Move the avatar left
            if(map[i][j-1]=='e'&& gamemap[i][j-1]!='o')
                gamemap[i][j-1];

        }
        else if (input == 'd'|| input == 'D') {
            // Move the avatar right
            if(map[i][j]+1=='e'&& gamemap[i][j+1]!='o')
                gamemap[i][j+1];

        }
        else if (input == 'h') {
            // Display help message
            cout << "Commands:" <<endl;
            cout << "w: move up" <<endl;
            cout << "s: move down" <<endl;
            cout << "a: move left" <<endl;
            cout << "d: move right" <<endl;
            cout << "h: display this help message" <<endl;
            cout << "p: pause the game and display information" << endl;
            cout << "q: quit the game" << endl;
            }
        else {
            cout << "Invalid command" << endl;
        }
    }

};

//class vampire
class vampire{
    public:
    int x,y,i,j,health,power,filter,defence;
    char** map;
    char** gamemap;

    int Start(){
        srand((int)time(0));
        
        filter=rand()%2;
        power=(rand()%2)+1;
        health=5;
        defence=(rand()%1)+1;
    }

    int move(){
        /*VAMPIRES*/     //κίνηση των vampires μέσα στον χάρτη σύμφωνα με τους περιορισμούς
        srand((int)time(0));

        while(health){
            int current=rand();
            int temp=(current%8)+1;
            if(temp==1){        //κίνηση επάνω και διαγώνια αριστερά
                if((i==0) || (j==0)){
                    break;
                }
                else if(map[i-1][j-1]=='e' && (gamemap[i-1][j-1]=='o')){
                    gamemap[i-1][j-1]=gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
            if(temp==2){       //κίνηση επάνω
                if(i==0){
                    break;
                }
                else if(map[i-1][j]=='e' && (gamemap[i-1][j]=='o')){
                    gamemap[i-1][j]==gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
            if(temp==3){        //κίνηση επάνω διαγώνια δεξιά
                if((i==0) || (j==y)){
                    break;
                }
                else if(map[i-1][j+1]=='e' && (gamemap[i-1][j+1]=='o')){
                    gamemap[i-1][j+1]=gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
            if(temp==4){        //κίνηση αριστερά
                if(j==0){
                    break;
                }
                else if(map[i][j-1]=='e' && (gamemap[i][j-1]=='o')){
                    gamemap[i][j-1]==gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
            if(temp==5){        //κίνηση δεξιά
                if(j==y){
                    break;
                }
                else if(map[i][j+1]=='e' && (gamemap[i][j+1]=='o')){
                    gamemap[i][j+1]==gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
            if(temp==6){        //κίνηση κάτω διαγώνια αριστερά
                if((i==x) || (j==0)){
                    break;
                }
                else if(map[i+1][j-1]=='e' && (gamemap[i+1][j-1]=='o')){
                    gamemap[i+1][j-1]=gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
            if(temp==7){        //κίνηση κάτω
                if(i==x){
                    break;
                }
                else if(map[i+1][j]=='e' && (gamemap[i+1][j]=='o')){
                    gamemap[i+1][j]==gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
            if(temp==8){        //κίνηση κάτω διαγώνια δεξιά
                if((i==x) || (j==y)){
                    break;
                }
                else if(map[i+1][j+1]=='e' && (gamemap[i+1][j+1]=='o')){
                    gamemap[i+1][j+1]=gamemap[i][j];
                    gamemap[i][j]='o';
                }
            }
        }
    }

    private:
        int x_,y_;
};


//class werewolf
class werewolf{
    public:
        int x,y,i,j,health,power,filter,defence;
        char** map;
        char** gamemap;
    int Start(){
            srand((int)time(0));
            
            int filter=rand()%2;
            int power=(rand()%2)+1;
            int hp=5;
            int defence=(rand()%1)+1;
    }
    int move(){
        
        srand((int)time(0));
        while(health){
        int current=rand();
        int temp=(current%4)+1;
        if(temp==1){       //κίνηση επάνω
            if(i==0){
                break;
            }
            else if(map[i-1][j]=='e' && (gamemap[i-1][j]=='o')){
                gamemap[i-1][j]==gamemap[i][j];
                gamemap[i][j]='o';
            }
        }
        if(temp==2){        //κίνηση αριστερά
            if(j==0){
                break;
            }
            else if(map[i][j-1]=='e' && (gamemap[i][j-1]=='o')){
                gamemap[i][j-1]==gamemap[i][j];
                gamemap[i][j]='o';
            }
        }
        if(temp==3){        //κίνηση δεξιά
            if(j==y){
                break;
            }
            else if(map[i][j+1]=='e' && (gamemap[i][j+1]=='o')){
                gamemap[i][j+1]==gamemap[i][j];
                gamemap[i][j]='o';
            }
        }
        if(temp==4){        //κίνηση κάτω
            if(i==x){
                break;
            }
            else if(map[i+1][j]=='e' && (gamemap[i+1][j]=='o')){
                gamemap[i+1][j]==gamemap[i][j];
                gamemap[i][j]='o';
            }
        }
    }

    }

    private:
        int x_,y_;
};


//keep playing or quit the game class 
void game(){
    cout<<"Do you want to keep playing?(Y/N)"<<endl;
    char input;
    cin>>input;
    if(input=='N'|| input=='n')          
        cout<<"exitig..."<<endl;
        
    else if (input=='q')            
        cout<<"exitig..."<<endl;
        
}

int main(){
    int x, y, i, j, maxplayers, earth, water, tree, current, temp, vampires, werewolfs, filter;
    long curtime;
    //time_t ti = time(NULL);
    char ch;

    cout<<"Choose two possitive numbers for the map[x.y]\n";
    cin>>x>>y;
    char map[x][y];
    char gamemap[x][y];

    cout<<"Choose a team to support between Vampires or Werewolf ['V' or 'W']\n";
    while(1){               //ο χρήστης μπορεί να δώσει μόνο δύο επιλογές για το ποια ομάδα προτιμάει
        cin>>ch;
        if((ch=='V')|| (ch=='v') || (ch=='W')|| (ch=='w')){
            break;
        }
    }

    maxplayers=(x*y)/15;    //το μέγιστο πλήθος των παιχτών κάθε ομάδας
    earth=(x*y)/2;          //ο μισός χάρτης θα έχει πεδία με γη
    water=tree=(x*y)/4;     //ο υπόλοιπος χάρτης θα είναι μοιρασμένος σε νερό και δέντρα
    if((earth+water+tree)!=(x*y)){
        earth++;            //σε περίπτωση που (x*y)/4 αφήνει υπόλοιπο αυξάνουμε το πεδίο της γης κατά ένα
    }

    //srand (ti);
    srand((int)time(0));

    for(i=0; i<x; i++){     //αρχικοποιούμε τον πίκανα του χάρτη με το o
        for(j=0; j<y; j++){
            map[i][j]='o'; 
        }
    }
    for(i=0; i<x; i++){     //αρχικοποιούμε τον πίκανα του χάρτη με το o
        for(j=0; j<y; j++){
            gamemap[i][j]='o'; 
        }
    }

    while(earth){           //γεμίζουμε τυχαία τον πίνακα με τα στοιχεία της γης
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                current=rand();
                temp=current%(x+y);
                if(((i+j)==temp) && (earth!=0) && (map[i][j]=='o')){
                    map[i][j]='e';
                    earth--;
                }
            }
        }
    }
    while(water){           //γεμίζουμε τυχαία τον υπόλοιπο πίνακα με τα στοιχεία του νερου
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                current=rand();
                temp=current%(x+y);
                if(((i+j)==temp) && (water!=0) && (map[i][j]=='o')){
                    map[i][j]='w';
                    water--;
                }
            }
        }
    }
    while(tree){            //γεμίζουμε τυχαία τον υπόλοιπο πίνακα με τα στοιχεία των δέντρων
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                current=rand();
                temp=current%(x+y);
                if(((i+j)==temp) && (tree!=0) && (map[i][j]=='o')){
                    map[i][j]='t';
                    tree--;
                }
            }
        }
    }

    int avatar=1;
    while(avatar){          //τοποθετούμε το Avatar σε τυχαία θέση στον χάρτη
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                current=rand();
                temp=current%(x+y);
                if(((i+j)==temp) && (avatar!=0) && (map[i][j]=='e')){
                    gamemap[i][j]='A';
                    avatar--;
                }
            }
        }
    }
    vampires=maxplayers;
    while(vampires){        //τοποθετούμε το V σε τυχαία θέση στον χάρτη
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                current=rand();
                temp=current%(x+y);
                if(((i+j)==temp) && (vampires!=0) && (map[i][j]=='e')){
                    gamemap[i][j]='V'; 
                    vampires--;
                }
            }
        }
    }
    werewolfs=maxplayers;
    while(werewolfs){       //τοποθετούμε το W σε τυχαία θέση στον χάρτη
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                current=rand();
                temp=current%(x+y);
                if(((i+j)==temp) && (werewolfs!=0) && (map[i][j]=='e')){
                    gamemap[i][j]='W';
                    werewolfs--;
                }
            }
        }
    }

    filter=1;
    while(filter){          //τοποθετούμε το φίλτρο σε τυχαία θέση στον χάρτη
        for(i=0; i<x; i++){
            for(j=0; j<y; j++){
                current=rand();
                temp=current%(x+y);
                if(((i+j)==temp) && (filter!=0) && (map[i][j]=='e')){
                    gamemap[i][j]='F';
                    filter--;
                }
            }
        }
    }

    for(i=0; i<x; i++){     //εμαφανίζουμε τον πίκανα του χάρτη
        for(j=0; j<y; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\t";
        for(j=0; j<y; j++){
            cout<<gamemap[i][j]<<" ";
        }
        cout<<"\n";
    }

    werewolf obj1;
    obj1.Start();
    vampire obj2;
    obj2.Start();
    Avatar obj;
    obj.Start();
while(true){
    obj.move();
    obj1.move();
    obj2.move();     

    for(i=0; i<x; i++){     //εμαφανίζουμε τον πίκανα του χάρτη
        for(j=0; j<y; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\t";
        for(j=0; j<y; j++){
            cout<<gamemap[i][j]<<" ";
        }
        cout<<"\n";
    }
    // Alternate between day and night
    static bool is_day = true;
    is_day = !is_day;

}
    game();

    return 0;
}