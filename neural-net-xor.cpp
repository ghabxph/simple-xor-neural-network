#include <iostream>

using namespace std;

/// --------------------------------
/// Prototypes
/// ````````````````````````````````
int getValidBinaryInput(const char *sMessage);
int getIntInput(const char *sMessage);
int doNeuralXor(int input1, int input2);
/// --------------------------------


/// --------------------------------
/// Application's entry point
/// ````````````````````````````````
int main()
{
    int input[2];
    int output;

    /// Gets 2 inputs (0 or 1 only)
    input[0] = getValidBinaryInput("Please enter input 1: ");
    input[1] = getValidBinaryInput("Please enter input 2: ");

    /// Displays the summary of our input
    cout << "Input 1: " << input[0] << endl;
    cout << "Input 2: " << input[1] << endl;

    /// Compute XOR using neural network
    output = doNeuralXor(input[0], input[1]);

    /// Displays the result of the computation (answer only)
    cout << "XOR (using neural network): " << output << endl;

    return 1;
}
/// --------------------------------


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
        cout << endl << sMessage;
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

/// Performs XOR operation using neural network
int doNeuralXor(int input1, int input2)
{
    return 0;
}
