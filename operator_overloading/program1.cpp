# include <iostream>
using namespace std;

class Space{
    int x;
    int y;
    int z;
    public: 
        void getdata(){
            cout<<"Enter x: ";
            cin>>x;
            cout<<"Enter y: ";
            cin>>y;
            cout<<"Enter z: ";
            cin>>z;
        }
        void display(){
            cout<<"X: "<<x<<" Y: "<<y<<" Z: "<<z<<endl;
        }
        void operator-(){
            x=-x;
            y=-y;
            z=-z;
        }
};

int main(){
    Space s;
    s.getdata();
    s.display();
    -s;
    s.display();
    return 0;
}