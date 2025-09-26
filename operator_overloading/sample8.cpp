# include <iostream>
using namespace std;

class Sample{
    int a;
    int b;
    char n;
    int arr[5];
    public:
        void display(){
            cout<<"A: "<<a<<"B: "<<b<<"N: "<<n<<endl;
            for(int i=0;i<5;i++){
                cout<<arr[i]<<endl;
            }
        }
};

int main(){
    static Sample S1;
    S1.display();
    return 0;
}