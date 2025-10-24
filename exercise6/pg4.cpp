#include <iostream>
using namespace std;

namespace MathOperations {
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }
}

namespace English {
    void greet() {
        cout << "Hello!" << endl;
    }
}

namespace Tamil {
    void greet() {
        cout << "Vanakkam!" << endl;
    }
}

namespace Geometry {
    const double PI = 3.14159;

    double areaOfCircle(double r) {
        return PI * r * r;
    }
}

namespace School {
    namespace Students {
        void display() {
            cout << "This is the Students namespace." << endl;
        }
    }

    namespace Teachers {
        void display() {
            cout << "This is the Teachers namespace." << endl;
        }
    }
}

using namespace Geometry;  

int main() {
    int a,b;
    cout<<"Enter a and b : ";
    cin>>a>>b;
    cout << "---- Basic Namespace ----" << endl;
    cout << "Sum: " << MathOperations::add(a,b) << endl;
    cout << "Difference: " << MathOperations::subtract(a,b) << endl;

    cout << "\n---- Multiple Namespaces ----" << endl;
    English::greet();
    Tamil::greet();
    int r;
    cout<<"Enter radius : ";
    cin>>r;
    cout << "\n---- Using Directive ----" << endl;
    cout << "Area of circle (r = 4): " << areaOfCircle(r) << endl;

    cout << "\n---- Nested Namespaces ----" << endl;
    School::Students::display();
    School::Teachers::display();

    return 0;
}