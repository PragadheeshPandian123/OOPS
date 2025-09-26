# include <iostream>
using namespace std;

class integer{
    int x;
    public:
        friend istream & operator >> (istream & inp , integer & n);
        friend ostream & operator << (ostream & out ,integer & n); 
};

istream & operator >> (istream & inp ,integer & n){
    inp>> n.x;
    return inp;
}

ostream & operator << (ostream & out , integer & n){
    out<< n.x;
    return out;
}