#include <iostream>
#include <string>
using namespace std;

class Restaurant {
public:
    string name;
    class Food {
    public:
        string foodName;
        double price;

        void display() {
            cout << "Food: " << foodName << ", Price: Rs." << price << endl;
        }
    };

    void showRestaurant() {
        cout << "Restaurant: " << name << endl;
    }
};

int main() {
    string name;
    float price;
    Restaurant r;
    cout<<"Enter the restaurant name: ";
    cin>>name;
    r.name = name;
    r.showRestaurant();

    Restaurant::Food dish1;
    cout<<"Enter the name of dish1: ";
    cin>>name;
    dish1.foodName =name ;
    cout<<"Enter price : ";
    cin>>price;
    dish1.price = price;
    dish1.display();

    Restaurant::Food dish2;
    cout<<"Enter the name of dish2: ";
    cin>>name;
    dish2.foodName = name;
    cout<<"Enter price : ";
    cin>>price;
    dish2.price = price;
    dish2.display();

    Restaurant::Food dish3;
    cout<<"Enter the name of dish3: ";
    cin>>name;
    dish3.foodName = name;
    cout<<"Enter price : ";
    cin>>price;
    dish3.price = price;
    dish3.display();

    return 0;
}
