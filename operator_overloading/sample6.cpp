# include <iostream>
using namespace std;
class Sample{
    static int count;
    public:
        Sample(){
            count++;
        }
        void show_count(){
            cout<<"Count: "<<count<<endl;
        }
};

int Sample::count=0;

int main(){
    Sample S1,S2,S3;
    S1.show_count();
    S2.show_count();
    Sample S4;
    S3.show_count();
    S4.show_count();
}