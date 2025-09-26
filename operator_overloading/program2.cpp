# include <iostream>
using namespace std;

class Integer {
    int a;
    public:
        Integer(){
            a=0;
        }
        Integer(int x){
            a=x;
        }
        void display(){
            cout<<"A : "<<a<<endl;
        }
        void operator - ();
        Integer operator + (Integer);
        Integer operator - (Integer);
};

void Integer :: operator-(){
    a=-a;
}

Integer Integer :: operator +(Integer B){
    return a + B.a;
}

Integer Integer :: operator-(Integer B){
    return a - B.a;
}

int main(){
    Integer x(5);
    Integer y(6);
    x.display();
    y.display();

    -x,-y;
    x.display();
    y.display();

    Integer z;
    z=x+y;
    z.display();
    z=x-y;
    z.display();
    return 0;
}