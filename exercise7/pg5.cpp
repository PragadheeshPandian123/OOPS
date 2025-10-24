#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item
{
public:
    int itemID;
    char itemName[50];
    float price;

    void input()
    {
        cout << "Enter Item ID: ";
        cin >> itemID;
        cin.ignore();
        cout << "Enter Item Name: ";
        cin.getline(itemName, 50);
        cout << "Enter Price: ";
        cin >> price;
    }

    void display()
    {
        cout << "ID: " << itemID
             << ", Name: " << itemName
             << ", Price: " << price << endl;
    }
};

// Function to create a file with initial items
void createFile(const char *filename)
{
    ofstream fout(filename, ios::binary);
    if (!fout)
    {
        cout << "Error creating file!" << endl;
        return;
    }

    int n;
    cout << "Enter number of items to add: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Item it;
        cout << "Enter details for item " << i + 1 << ":\n";
        it.input();
        fout.write((char *)&it, sizeof(it));
    }

    fout.close();
    cout << "File created successfully!" << endl;
}

// Function to append a new item
void appendItem(const char *filename)
{
    ofstream fout(filename, ios::binary | ios::app);
    if (!fout)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Item it;
    cout << "Enter details of new item:\n";
    it.input();
    fout.write((char *)&it, sizeof(it));

    fout.close();
    cout << "Item appended successfully!" << endl;
}

// Function to display all items
void displayAll(const char *filename)
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Item it;
    cout << "\n--- Items in File ---\n";
    while (fin.read((char *)&it, sizeof(it)))
    {
        it.display();
    }

    fin.close();
}

// Function to update item price
void updatePrice(const char *filename)
{
    fstream fio(filename, ios::binary | ios::in | ios::out);
    if (!fio)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int id;
    cout << "Enter Item ID to update price: ";
    cin >> id;

    Item it;
    bool found = false;
    while (fio.read((char *)&it, sizeof(it)))
    {
        if (it.itemID == id)
        {
            cout << "Current details:\n";
            it.display();
            cout << "Enter new price: ";
            cin >> it.price;

            // Move write pointer back to overwrite the current record
            fio.seekp(-sizeof(it), ios::cur);
            fio.write((char *)&it, sizeof(it));
            found = true;
            cout << "Price updated successfully!" << endl;
            break;
        }
    }

    if (!found)
        cout << "Item ID not found!" << endl;

    fio.close();
}

// Function to delete an item
void deleteItem(const char *filename)
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream fout("temp.dat", ios::binary);
    int id;
    cout << "Enter Item ID to delete: ";
    cin >> id;

    Item it;
    bool found = false;
    while (fin.read((char *)&it, sizeof(it)))
    {
        if (it.itemID == id)
        {
            found = true;
            continue; // skip writing this record
        }
        fout.write((char *)&it, sizeof(it));
    }

    fin.close();
    fout.close();

    remove(filename);             // delete original file
    rename("temp.dat", filename); // rename temp to original

    if (found)
        cout << "Item deleted successfully!" << endl;
    else
        cout << "Item ID not found!" << endl;
}

void countItems(const char *filename)
{
    ifstream fin(filename, ios::binary);
    if (!fin)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    fin.seekg(0, ios::end);           // move to end of file
    streampos fileSize = fin.tellg(); // get file size in bytes
    int numObjects = fileSize / sizeof(Item);
    cout << "Number of items in the file: " << numObjects << endl;

    fin.close();
}

int main()
{
    const char *filename = "items.dat";
    int choice;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Create file with items\n";
        cout << "2. Append new item\n";
        cout << "3. Delete an item\n";
        cout << "4. Update item price\n";
        cout << "5. Display all items\n";
        cout << "6. Count number of items\n"; // new option
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createFile(filename);
            break;
        case 2:
            appendItem(filename);
            break;
        case 3:
            deleteItem(filename);
            break;
        case 4:
            updatePrice(filename);
            break;
        case 5:
            displayAll(filename);
            break;
        case 6:
            countItems(filename);
            break; // call count function
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
