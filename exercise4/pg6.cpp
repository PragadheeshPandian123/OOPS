# include <iostream>
using namespace std;

class Distance{
    int kms,m;
    public:
        Distance(){
            kms=m=0;
        }
        Distance (int D){
            kms=D/1000;
            m=D%1000;
        }
        void get_data(){
            cin>>kms>>m;
        }
        void show_data(){
            cout<<kms<< "kms"<<m<<" mts\n";
        }
        operator int(){
            int D = kms*1000 + m;
            return D;
        }
        operator float(){
            float Distance_kms=kms + (float)m/1000;
            return Distance_kms;
        }
};

int main(){
    int dist;
    cout<<"\n Enter the distance in metres: ";
    cin>>dist;
    Distance D1;
    D1=dist;
    D1.show_data();
    cout<<"Enter the number of kms and metres: ";
    D1.get_data();
    dist=D1;
    cout<<"\n Total Metres = "<<dist;
    float k=D1;
    cout<<"\n Total Kilometres = "<<k;
}