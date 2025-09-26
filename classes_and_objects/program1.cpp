#include <iostream>
using namespace std;

class Rectangle {
    int length, width;

public:
    void getdata(int l, int w) {
        length = l;
        width = w;
    }
    int area();
    int perimeter();
    void display() ;
};
int Rectangle::area()
{
    return length * width;
}
int Rectangle::perimeter()
{
    return 2*(length+width);
}
void Rectangle::display()
{
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
int main() {
    Rectangle r; 
    int l,w;
    cout<<"Enter length: ";
    cin>>l;
    cout<<"Enter width: ";
    cin>>w;
    r.getdata(l,w);  
    r.display();             

    return 0;
}
