#include "Complex_number.h"
#include <iostream>
//Menu for console
void print_menu(void)
{
    cout << "\n -----------------------------------------------\n";
    cout << "|0. Exit from Application                       |\n";
    cout << "|1. Switch form.                                |\n";
    cout << "|2. Write to number.                            |\n";
    cout << "|3. Display number.                             |\n";
    cout << "|4. X + Y.                                      |\n";
    cout << "|5. X - Y.                                      |\n";
    cout << "|6. X * Y.                                      |\n";
    cout << "|7. X / Y.                                      |\n";
    cout << "|8. Raise to power/root                         |\n";
    cout << "|9. Comparing numbers                           |\n";
    cout << "|a. Operator []                                 |\n";
    cout << " -----------------------------------------------\n";
}

int choose_number(const char *message)
{
    int key;
    cout << "Choose number " << message << endl;
    cout << "1 - X\n";
    cout << "2 - Y\n";
    cout << "3 - Z[]\n";
    cin >> key;
    return key;
}

