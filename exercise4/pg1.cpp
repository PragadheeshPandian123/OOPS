# include <iostream>
using namespace std;

class Number {
    int x;
    public:
        Number(){
            x=0;
        }
        Number(int a){
            x=a;
        }
        Number operator -(){
            return Number(-x);
        }
        Number operator ++(){
            x=x+1;
            return Number(x);
        }
        friend Number operator--(Number &a);
        friend Number operator++(Number &a,int);
        friend Number operator--(Number &b,int);
        void display(){
            cout<<"X: "<<x<<endl;
        }
};
Number operator--(Number &a){
    a.x=a.x-1;
    return Number(a.x);
}

Number operator++(Number &a,int){
    return Number(a.x++);
}
Number operator--(Number &b,int){
    return Number(b.x--);
}

int main(){
    Number n1;
    Number n2(5);
    cout<<"N1: "<<endl;
    n1.display();
    cout<<"N2: "<<endl;
    n2.display();
    cout<<"Performing operations on N2 and assigning to N1: "<<endl;
    cout<<"Unary Minus operator: "<<endl;
    n1=-n2;
    n1.display();
    cout<<"Pre-Increement operator: "<<endl;
    n1=++n2;
    n1.display();
    cout<<"Pre-Decreement operator: "<<endl;
    n1=--n2;
    n1.display();
    cout<<"Post-Increement operator: "<<endl;
    n1=n2++;
    n1.display();
    cout<<"Post-Decreement operator: "<<endl;
    n1=n2--;
    n1.display();
    return 0;
}