# include <iostream>
using namespace std;

class Number{
    int x;
    public:
        Number(){
            x=0;
        }
        Number(int a){
            x=a;
        }
        Number operator ++(){//prefix
            x++;
            return Number(x);
        }
        Number operator --(){//prefix
            x--;
            return Number(x);
        }
        
        void show_data(){
            cout<<"X: "<<x<<endl;
        }
};


int main(){
    Number N1(5),N2;
    N1.show_data();
    
    cout<<"PREFIX: "<<endl;
    cout<<"INCREEMENT: "<<endl;

    N2=N1++;
    N1.show_data();
    N2.show_data();
    
    cout<<"DECREEMENT: "<<endl;
    N2=N1--;
    N1.show_data();
    N2.show_data();

    cout<<"POSTFIX: "<<endl;
    cout<<"INCREEMENT: "<<endl;

    return 0;
}