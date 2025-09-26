# include <iostream>
using namespace std;

class ID_Generator{
    static int nextid;
    public:
        void display(){
            cout<<"Next id: "<<nextid++<<endl;
        }
};
int ID_Generator::nextid=1;
int main(){
    ID_Generator id1;
    id1.display();
    id1.display();
}