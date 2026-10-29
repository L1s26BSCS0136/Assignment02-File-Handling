```cpp
/*
 * Name       : M TALHA
 * Reg No     : L1S26BSCS0136
 * Assignment : 02 - File Handling
 * Question   : Q5 - Expense Tracker
 */

#include <iostream>
#include <fstream>
#include <cstring>
    using namespace std;

int main()
{
    int choice;
    char category[20], categories[100][20];
    int amounts[100];

    do
    {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter category: ";
            cin >> category;

            cout << "Enter amount: ";
            int amount;
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Invalid amount!" << endl;
            }
            else
            {
                ofstream outFile("expenses.txt", ios::app);

                outFile << category << " "
                    << amount << endl;

                outFile.close();

                cout << "Expense saved." << endl;
            }
        }
        else if (choice == 2)
        {
            ifstream inFile("expenses.txt");

            int count = 0, total = 0;
            int largest = 0;
            char largestCategory[20];

            while (count < 100 &&
                inFile >> categories[count] >> amounts[count])
            {
                total += amounts[count];

                if (count == 0 || amounts[count] > largest)
                {
                    largest = amounts[count];
                    strcpy(largestCategory, categories[count]);
                }

                count++;
            }

            inFile.close();

            if (count == 0)
            {
                cout << "No expenses yet." << endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    cout << i + 1 << ". "
                        << categories[i] << " "
                        << amounts[i] << endl;
                }

                cout << "Total spent: " << total << endl;
                cout << "Largest expense: "
                    << largestCategory << " ("
                    << largest << ")" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Enter category: ";
            cin >> category;

            ifstream inFile("expenses.txt");

            int amount, count = 0, total = 0;
            char savedCategory[20];

            while (inFile >> savedCategory >> amount)
            {
                if (strcmp(savedCategory, category) == 0)
                {
                    count++;
                    total += amount;
                }
            }

            inFile.close();

            if (count == 0)
            {
                cout << "No expenses found for "
                    << category << endl;
            }
            else
            {
                cout << "Expenses in Category: "
                    << count << endl;
                cout << "Total for Category: "
                    << total << endl;
            }
        }
        else if (choice == 4)
        {
            ofstream outFile("expenses.txt");
            outFile.close();

            cout << "All expenses cleared." << endl;
        }
        else if (choice == 5)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
```