#include <iostream>
using namespace std;
template <class Type>
class EvenOdd;
template <class Type>
class Array
{
public:
    Type *arr;
    int size;
    Array(int num)
    {
        size = num;
        arr = new Type[size];
    }
    void read()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "\t" << arr[i];
        }
        cout << endl;
    }
    friend class EvenOdd<Type>;
};
template <class Type>
class EvenOdd
{
private:
    Type even_arr[10];
    int size_even;
    Type odd_arr[10];
    int size_odd;

public:
    void create_arrs(Array<Type> &A)
    {
        int index1 = 0, index2 = 0;
        size_even = size_odd = 0;
        for (int i = 0; i < A.size; i++)
        {
            if (A.arr[i] % 2 == 0)
            {
                even_arr[index1] = A.arr[i];
                index1++;
            }
            else
            {
                odd_arr[index2] = A.arr[i];
                index2++;
            }
        }
        size_even = index1;
        size_odd = index2;
    }
    void printevenodd()
    {
        cout << "\nEven elements are: ";
        for (int i = 0; i < size_even; i++)
            cout << "\t" << even_arr[i];
        cout << "\nOdd elements are: ";
        for (int i = 0; i < size_odd; i++)
            cout << "\t" << odd_arr[i];
        cout << endl;
    }
};
int main()
{
    Array<int> A(12);
    cout << "Enter the elements of the array: ";
    A.read();
    EvenOdd<int> EO;
    EO.create_arrs(A);
    EO.printevenodd();
    return 0;
}