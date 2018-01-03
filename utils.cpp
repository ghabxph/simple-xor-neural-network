#include "utils.h"

/// Gets valid binary input
int getValidBinaryInput(const char *sMessage)
{
    bool bInputGood = false;
    int iInput;
    do {
        iInput = getIntInput(sMessage);
        bInputGood = iInput == 0 || iInput == 1;
        if (bInputGood == false) {
            cout << "Enter only 1 or 0." << endl;
        }
    } while (bInputGood == false);
    return iInput;
}

/// Retrieves valid integer input from input stream
int getIntInput (const char *sMessage)
{
    bool bInputGood = false;
    int inputVar;
    do {
        cout << sMessage;
        cin >> inputVar;
        bInputGood = cin.good();
        if (bInputGood == false) {
            cout << "Bad input. Please try again." << endl;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } while (bInputGood == false);
    return inputVar;
}

