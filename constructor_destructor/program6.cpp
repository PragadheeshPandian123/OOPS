# include <iostream>
# include <string.h>
using namespace std;

class String{
    private:
        int length;
        int num_vowels;
        int num_uppers;
        int num_words;
        int num_characters;
        char * str;
    public:
        String()
        {
            length=0;
            num_vowels=0;
            num_uppers=0;
            num_words=1;
            num_characters=0;
        }
        String (const char *s){
          length=strlen(s);
            num_vowels=0;
            num_uppers=0;
            num_words=1;
            num_characters=0;
            str=new char [length+1];
            strcpy(str,s);
        }
        void show_str()
        {
            cout.write(str,length);
        }
        void show_details();
};
void String::show_details(){
    int i=0;
    while(str[i]!='\0'){
        switch(str[i]){
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                num_vowels++;
                break;
        }
        if(str[i>='A']&&str[i]<='Z'){
            num_uppers++;
        }
        if(str[i]==' '&&str[i+1]!=' '){
            num_words++;
        }
        i++;
    }
    cout<<"\n Number of Vowels = "<<num_vowels;
    cout<<"\n Number of upper case characters = "<<num_uppers;
    cout<<"\n Number of characters = "<<num_characters;
    cout<<"\n Number of words = "<<num_words;
}
int main(){
    String s1("Welcome To The World of Programming");
    s1.show_str();
    s1.show_details();
}