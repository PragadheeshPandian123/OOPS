# include <iostream>
# include <string>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    cin>>str;
    string rev_Str="";
    for(int i=str.length()-1;i>=0;i--){
        rev_Str+=str[i];
    }
    cout<<"The original string is: "<<str<<endl;
    cout<<"The reversed string is : "<<rev_Str<<endl;
    return 0;
}