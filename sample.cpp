# include <iostream>
using namespace std;

class Space{
    int x;
    int y;
    int z;
    public:
        Space(int ,int ,int);
        void operator -();
        void display();
};

Space:: Space(int a,int b,int c){
    x=a,y=b,z=c;
}

void Space:: operator-(){
    x=-x,y=-y,z=-z;
}

void Space:: display(){
    cout<<" x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
}

int main()
{
    Space S1(3,4,5);
    S1.display();
    return 0;
}