# include <iostream>
using namespace std;

class Sample{
    int x;
    public:
        Sample(){
            x=0;
        }
        Sample(int a){
            x=a;
        }
        void show_data() const{
            cout<<"X: "<<x<<endl;
        }
        friend Sample operator-(const Sample &);
        friend Sample & operator ++(Sample &);
};

Sample operator - (const Sample & S1){
    Sample temp(-S1.x);
    return temp;
}

Sample & operator ++(Sample & S1){
    S1.x=S1.x+1;
    return S1;
}

int main(){
    const Sample S1(5);
    Sample S2=-S1;
    S1.show_data();
    S2.show_data();
    Sample S3=++S2;
    S3.show_data();
    return 0;
}