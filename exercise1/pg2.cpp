# include <iostream>
using namespace std;

int main(){
    char op;
    int num1,num2;
    cout<<"Enter num1: ";
    cin>>num1;
    cout<<"Enter num2: ";
    cin>>num2;
    cout<<"Enter operator(+,-,/,*,%): ";
    cin>>op;
    if(op=='+'){
        cout<<num1<<" + "<<num2<<" = "<<num1+num2;
    }
    else if(op=='-'){
        cout<<num1<<" - "<<num2<<" = "<<num1-num2;
    }
    else if(op=='*'){
        cout<<num1<<" * "<<num2<<" = "<<num1*num2;
    }
    else if(op=='/'){
        if(num2==0){
            cout<<"Zero Division Error"<<endl;
        }
        else{
            cout<<num1<<" / "<<num2<<" = "<<num1/num2;
        }
    }
    else if(op=='%'){
        cout<<num1<<" % "<<num2<<" = "<<num1%num2;
    }
    return 0;
}
