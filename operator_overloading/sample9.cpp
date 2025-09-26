# include <iostream>
using namespace std;

class Faculty{
    char name[20];
    char dept[20];
    public:
        void get_data(){
            cout<<"Enter the name: ";
            cin.getline(name,20);
            cout<<"Enter the department: ";
            cin.getline(dept,20);
        }
        void show_data(){
            cout<<"Name: "<<name<<endl;
            cout<<"Department: "<<dept<<endl;
        }
};

int main(){
    Faculty **f=new Faculty*[5];
    for(int i=0;i<5;i++){
        f[i]=new Faculty;
        f[i]->get_data();
    }
    for(int i=0;i<5;i++){
        f[i]->show_data();
    }
    return 0;
}