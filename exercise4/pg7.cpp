# include <iostream>
using namespace std;
class Rectangle;
class Square{
    int side;
    public:
        Square(int s){
            side=s;
        }
        int get_side(){
            return side;
        }
};

class Rectangle{
    int length,breadth;
    public:
        Rectangle(int l,int b){
            length=l;
            breadth=b;
        }
        Rectangle(Square s){
            length=breadth=s.get_side();
        }
        void show_data(){
            cout<<"\n Length = "<<length<<" and breadth = "<<breadth;
        }
};
int main(){
    Rectangle R(10,20);
    R.show_data();
    Square S(50);
    R=S;
    R.show_data();
    return 0;
}