# include <iostream>
using namespace std;

class Complex{
    float x;
    float y;
    public:
        Complex (){
            x=0,y=0;
        }
        Complex(float,float);
        void display();
        friend Complex operator+(Complex &,Complex &);
};


Complex:: Complex(float a,float b){
    x=a,y=b;
}

Complex operator+(Complex & C1,Complex & C2){
    Complex temp;
    temp.x=C1.x + C2.x;
    temp.y=C1.y + C2.y;
    return temp;
}

void Complex :: display(){
    cout<<"Real : "<<x<<endl;
    cout<<"Imaginary : "<<y<<endl;
}

int main(){
    Complex c1,c2,c3;
    c1=Complex(2,3.9);
    c2=Complex(3.1,4);
    c3=c1+c2;
    c3.display();
}