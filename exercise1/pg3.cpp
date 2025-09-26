# include <iostream>
using namespace std;

int main(){
    int num,count;
    cout<<"Enter num: ";
    cin>>num;
    cout<<"Enter number of times: ";
    cin>>count;
    cout<<"Using While loop: "<<endl;
    int i=1;
    while(i<=count){
        cout<<num<<" * "<<i<<" = "<<num*i<<endl;
        i++;
    }
    cout<<"Using For loop"<<endl;
    for(int i=1;i<=count;i++){
        cout<<num<<" * "<<i<<" = "<<num*i<<endl;
    }
    i=1;
    cout<<"Using Do while loop"<<endl;
    do{
        cout<<num<<" * "<<i<<" = "<<num*i<<endl;
        i++;
    }while(i<=count);
    return 0;
}