#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;

    virtual ~Shape() {
        cout << "Shape destructor called\n";
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    ~Circle() {
        cout << "Circle destructor called\n";
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
    ~Rectangle() {
        cout << "Rectangle destructor called\n";
    }
};

int main() {
    float r,l,b;
    cout<<"Enter radius : ";
    cin>>r;
    cout<<"Enter length : ";
    cin>>l;
    cout<<"Enter breadth : ";
    cin>>b;
    Shape* s1 = new Circle(r);
    Shape* s2 = new Rectangle(l,b);

    cout << "Circle Area: " << s1->area() << endl;
    cout << "Rectangle Area: " << s2->area() << endl;

    delete s1;  
    delete s2; 

    return 0;
}