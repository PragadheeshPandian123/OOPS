# include <iostream>
# include <iomanip>
using namespace std;
class Fraction{
    int num;
    int deno;
    void simplify();
    int GCD(int a,int b);
    public:
        void setdata(){
            cout<<"Enter num and deno: ";
            cin>>num>>deno;
            if(deno==0){
                cout<<"Fraction no possible.";
                exit(1);
            }
        }
        void display(){
            simplify();
            cout<<num<<"/"<<deno<<endl;
        }
};

void Fraction::simplify(){
    int cdiv=GCD(num,deno);
    num/=cdiv;
    deno/=cdiv;
}

int Fraction::GCD(int a,int b){
    if(b==0)
        return a;
    else{
        return GCD(a,b%a);
    }
}

int main(){
    Fraction f1;
    f1.setdata();
    f1.display();
}