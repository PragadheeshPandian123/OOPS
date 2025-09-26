# include <iostream>
using namespace std;
class Person{
    int y;
    public:
        int get_data(){
            return y;
        }
};
class Sample{
    int x;
    public:
        void get_data(){
            cout<<"Enter x :";
            cin>>x;
        }
        void display_another_class(Sample &s){
            s.x++;
            cout<<s.x<<endl;
        }
};