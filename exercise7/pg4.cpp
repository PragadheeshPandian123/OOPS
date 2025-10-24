#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout("user_input.txt");
    if (!fout) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    int n;
    cout << "How many lines do you want to enter? ";
    cin >> n;
    cin.ignore(); // clear newline left in buffer

    cout << "Enter " << n << " lines of text:\n";
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);  // read full line including spaces
        fout << line << endl; // write to file
    }

    fout.close(); // close file

    // Read and display the file content
    ifstream fin("user_input.txt");
    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "\nContents of the file:\n";
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();
    return 0;
}
