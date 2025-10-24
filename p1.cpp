#include <iostream>
using namespace std;
class Number {
    int value;
public:
    Number(int v) : value(v) {}
    Number operator/(int divisor) {
        try {
            if (divisor == 0)
                throw "Division by zero!";
            return Number(value / divisor);}
        catch (const char* msg) {
            cout << "Caught inside operator/: " << msg << endl;
            return Number(0);  }}
    void display() { cout << "Value: " << value << endl; }
};
int main() {
    Number num(10);
    Number result = num / 0;  
    result.display();
    Number result2 = num / 2; 
    result2.display();
    return 0;
}
