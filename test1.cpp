#include "libraries.h"
using namespace std;


//class avatar
class Avatar {
public:
    Avatar(int x, int y);

    int move(){   
        // Get user input (W-A-S-D)
        cout << "Use W-S-A-D to move " <<endl;
        char input;
        cin >> input;
        Themap themap;
        int i,j;
        if (input == 'w' || input == 'W') {
            // Move the avatar up
            themap.gamemap[i+1][j];
        }
        else if (input == 's'|| input == 'S') {
            // Move the avatar down
            themap.gamemap[i-1][j];
        }
        else if (input == 'a'|| input == 'A') {
            // Move the avatar left
            themap.gamemap[i][j-1];

        }
        else if (input == 'd'|| input == 'D') {
            // Move the avatar right
            themap.gamemap[i][j+1];

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
       int x,y; 
};

//class Themap
class Themap{
    private:
        

    public:
        int x, y, i, j, tree, current, temp, vampires, werewolfs, filter;
        long curtime;
        int maxplayers,earth,water;
        unsigned char** map;
        unsigned char** gamemap;
        //time_t ti = time(NULL);

        int arrays(){
            cout<<"Choose two possitive numbers for the map[x.y]\n";
            cin>>x>>y;
            map[x][y];
            gamemap[x][y];
            
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
        }




        int Nature(){
            srand((int)time(0));
            maxplayers=(x*y)/15;    //το μέγιστο πλήθος των παιχτών κάθε ομάδας
            earth=(x*y)/2;          //ο μισός χάρτης θα έχει πεδία με γη
            water=tree=(x*y)/4;     //ο υπόλοιπος χάρτης θα είναι μοιρασμένος σε νερό και δέντρα
        
            if((earth+water+tree)!=(x*y)){
                earth++;            //σε περίπτωση που (x*y)/4 αφήνει υπόλοιπο αυξάνουμε το πεδίο της γης κατά ένα
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
        }

        int Vmpires(){
            srand((int)time(0));
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
        }

        int Wwolves(){
            srand((int)time(0));
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
        }

        int Avatar(){
            srand((int)time(0));
            int avatar=1;     //τοποθετούμε το A σε τυχαία θέση στον χάρτη
            if((map[i][j]=rand()%i) && (map[i][j]=='e')){
                gamemap[i][j]='A';
                avatar--;
                }
        }

        int potion(){
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
        }


        int Show(){
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
        }
        


};

int main(){
    char ch;
    Themap themap;
    themap.arrays();
    
    cout<<"Choose a team to support between Vampires or Werewolf ['V' or 'W']\n";
    while(1){               //ο χρήστης μπορεί να δώσει μόνο δύο επιλογές για το ποια ομάδα προτιμάει
        cin>>ch;
        if((ch=='V')|| (ch=='v') || (ch=='W')|| (ch=='w')){
            break;
        }
    }
    themap.Show();

    
    


    return 0;
}



