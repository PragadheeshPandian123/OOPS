# include <iostream>
using namespace std;
class Line{
    float l;
    public:
        Line(){l=0;}
        Line(float r){l=r;}
        void show(){
            cout<<"Length: "<<l;
        }
};
class Circle{
    float r;
    public:
        Circle(){r=0;}
        Circle(int l){r=l;}
        operator Line(){
            float l=2*3.14*r;
            return Line(l);
        }
        void show(){
            cout<<"Radius: "<<r<<endl;
        }
};

int main(){
    Circle c(5);
    c.show();
    Line l=c;
    l.show();
    return 0;
}