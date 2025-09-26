# include <iostream>
using namespace std;

class Sample{
    public:
    static int count;
    public:
        void show_count(){
            cout<<"count: "<<count<<endl;
        }
};
int Sample::count=1;

int main(){
    Sample s1,s2,s3;
    s1.show_count();
    s2.show_count();
    s3.show_count();

    cout<<sizeof(Sample::count)<<endl;
    return 0;    
}