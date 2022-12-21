#include "libraries.h"
using namespace std;
using std::vector;


class map{

    private:
        int x,y;
        vector<vector<int> > my2DArray;

    public:
        //constructor for the length and width
        map(int a,int b){
        cout<<"Please type the length of the map from 0-10"<<endl<<"L:";
        cin>>a;
        cout<<"Please type the width of the map from 0-10"<<endl<<"W:";
        cin>>b;

        my2DArray.resize(a);
        for (int i = 0; i < a; ++i)
            my2DArray[i].resize(b);

        a=x;
        b=y;
        }


        // De-Constructor
        ~map(){} 
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


class earth{
    
    private:

    public:
};


class water{
    
    private:

    public:
};

class trees{

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

    my2DArray[Length][Width];
    cout<<"Type the teammates you want to have, V for vampires/ W for werewolves "<<endl;
    char team;
    cin>>team;
    if (team =='V'){
        vampires x;
    }
    else{
        werewolves x;
    }


    return 0;

}
