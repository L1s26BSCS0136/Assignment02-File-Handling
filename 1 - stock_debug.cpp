/*
* Name       : M TALHA
* Reg No     : L1S26BSCS0136
* Assignment : 02 - File Handling
* Question   : Q1 - Stock Report (Debugging)
*/

#include <iostream>
// FIX 1: Add fstream header for file handling
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("stock.txt");

    // FIX 2: Check the file failed to open
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    // FIX 3: Append new low-stock items without deleting old data
    ofstream reorder("reorder.txt", ios::app);

    char code[10];
    int qty, count = 0, low = 0;
    double price;

    // FIX 4: Use double to preserve decimal stock values
    double total = 0;

    // FIX 5: Skip the header line (Code Qty Price)
    inFile.ignore(100, '\n');

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;

        if (qty < 10) {
            // FIX 6: Write each item on a separate line
            reorder << code << " " << qty << endl;
            low++;
        }
    }

    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;

    return 0;
}