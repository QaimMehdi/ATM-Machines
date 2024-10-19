#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    double Balance, Deposit, Withdraw;
    int option;


    srand(time(0));

    int accountNumber = rand() % 10000 + 1000;

    Balance = 100;
    cout << "\n\n\n\t\t\t\t\t***************MENU***************" << endl;
    cout << "\t\t\t\t\t*                                *" << endl;
    cout << "\t\t\t\t\t*        1. Create Account       *" << endl;
    cout << "\t\t\t\t\t*        2. Exit                 *" << endl;
    cout << "\t\t\t\t\t*                                *" << endl;
    cout << "\t\t\t\t\t**********************************" << endl;
    cout << "\t\t\t\t\tPlease choose an option ";
    cin >> option;

    if (option == 1) {
        cout << "\n\t\t\t\tYour account has been created successfully." << endl;
        cout << "\t\t\t\tYour account number is: " << accountNumber << endl;
        cout << "\t\t\t\tPlease remember your account number." << endl;
    } else if (option == 2) {
        cout << "\n\t\t\t\tGoodbye!" << endl;
        return 0;
    } else {
        cout << "\n\t\t\t\tInvalid Option. Exiting..." << endl;
        return 0;
    }


    do {
        cout << "\n\n\n\t\t\t\t\t***************MENU***************" << endl;
        cout << "\t\t\t\t\t*                                *" << endl;
        cout << "\t\t\t\t\t*        1. Check Balance        *" << endl;
        cout << "\t\t\t\t\t*        2. Deposit              *" << endl;
        cout << "\t\t\t\t\t*        3. Withdraw             *" << endl;
        cout << "\t\t\t\t\t*        4. Exit                 *" << endl;
        cout << "\t\t\t\t\t*                                *" << endl;
        cout << "\t\t\t\t\t**********************************" << endl;
        cout << "\t\t\t\t\tPlease choose an option ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "\n\t\t\t\tYour Balance is: $" << Balance << endl;
                break;
            case 2:
                cout << "\n\t\t\t\tAmount you want to Deposit: $ ";
                cin >> Deposit;
                Balance += Deposit;
                cout << "\t\t\t\tYour Current Balance is: $" << Balance << endl;
                break;
            case 3:
                cout << "\n\t\t\t\tHow much do you want to Withdraw? ";
                cin >> Withdraw;
                if (Withdraw > Balance) {
                    cout << "\n\t\t\t\tInsufficient funds!" << endl;
                } else {
                    Balance -= Withdraw;
                    cout << "\t\t\t\tYour Current Balance is: $" << Balance << endl;
                }
                break;
            case 4:
                cout << "\n\t\t\t\tGoodbye!" << endl;
                break;
            default:
                cout << "\n\t\t\t\tInvalid Option, Please Try Again" << endl;
                break;
        }

    } while (option != 4);

    return 0;
}
