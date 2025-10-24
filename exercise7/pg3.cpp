#include <iostream>
#include <fstream>
#include <cctype>   
using namespace std;

void copyUpper() {
    ifstream fin("file1.txt");   
    ofstream fout("file2.txt");  

    if (!fin) {
        cout << "Error: Could not open file1.txt" << endl;
        return;
    }

    if (!fout) {
        cout << "Error: Could not create file2.txt" << endl;
        return;
    }

    char ch;
    while (fin.get(ch)) {  
        fout.put(toupper(ch));  
    }

    cout << "File copied in uppercase to file2.txt successfully!" << endl;

    fin.close();
    fout.close();
}

int main() {
    copyUpper();  
    return 0;
}
