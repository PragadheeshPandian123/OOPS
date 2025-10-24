#include <iostream>
using namespace std;
template <class Type>
float area(Type l, Type b)
{
    return l * b;
}
template <class Type>
float area(Type side)
{
    return side * side;
}
template <class Type>
float area(Type l, Type b, Type h)
{
    return l * b * h;
}
template <class Type1, class Type2, class Type3>
void area(Type1 PI, Type2 r, Type3 h, Type3 &result)
{
    result = PI * r * r * h;
}
int main()
{
    float length, breadth;
    cout<<"Enter length and breadth of rectangle : ";
    cin>>length>>breadth;
    float area_rect = area(length, breadth);
    cout << "\nArea of the Rectangle with Length " << length
         << " and Breadth " << breadth << " = " << area_rect;
    int l , b , h ;
    cout<<"Enter lenghth breadth and height of box : ";
    cin>>l>>b>>h;
    int area_box = area(l, b, h);
    cout << "\nArea of the Box with Length " << l
         << ", Breadth " << b << " and Height " << h << " = " << area_box;
    int s ;
    cout<<"Enter side of the square : ";
    cin>>s;
    int area_square = area(s);
    cout << "\nArea of the Square with Side " << s
         << " = " << area_square;
    float PI = 3.14;
    int radius ;
    double height, a;
    cout<<"Enter radius and height of cylinder :";
    cin>>radius>>height;
    area(PI, radius, height, a);
    cout << "\nVolume of the Cylinder with Radius " << radius
         << " and Height " << height << " = " << a << endl;
    return 0;
}