#include "libraries.h"
using namespace std;

class Point
{
    public:
        int x, y;
};



class map{

    private:
       int x,y;


    public:
        //constructor for the length and width
        map(int a, int b){
        cout<<"Please type the length of the map from 0-10"<<endl<<"L:";
        cin>>a;
        if (a<0 || a>10){
            cout<<"Try again...";
            cin>>a;
        }

        cout<<"Please type the width of the map from 0-10"<<endl<<"W:";
        cin>>b;
        if (b<0 || b>10){
            cout<<"Try again...";
            cin>>b;
        }

        x=a;
        y=b;
        }
        
};




class vampires{
    
    private:
       
    public:
};

class werewolves{
    
    private:

    public:
};

class avatar{
    
    private:
       
    public:
};

class health{
    
    private:
       
    public:
};

class med{
    
    private:
       
    public:
};

class power{
    
    private:
       
    public:
};






int main(){

    map<x, y> tm;

    return 0;

}
