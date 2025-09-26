# include <iostream>
using namespace std;

class Rectangle{
    float length;
    float breadth;
    public:
        void get_data(){
            cout<<"Enter length and breadth: ";
            cin>>length>>breadth;
        }
        void display(){
            cout<<"Length: "<<length<<endl;
            cout<<"Breadth: "<<breadth<<endl;
        }

};

int main(){
    Rectangle R1;
    R1.get_data();
    R1.display();
    return 0;
}