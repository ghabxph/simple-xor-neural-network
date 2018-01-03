#include <iostream>
#include <math.h>

using namespace std;

/// --------------------------------
/// Prototypes
/// ````````````````````````````````
int getValidBinaryInput(const char *sMessage);
int getIntInput(const char *sMessage);
int doNeuralXor(int input1, int input2);
double sigmoid(double value);
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

    cout << endl;

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

/// Performs XOR operation using neural network
int doNeuralXor(int input1, int input2)
{
    double inputWeight1[3];
    double inputWeight2[3];
    double hiddenWeight[3];
    double hiddenNeuron[3];
    double output = 0;
    inputWeight1[0] = 0.8;
    inputWeight1[1] = 0.4;
    inputWeight1[2] = 0.3;
    inputWeight2[0] = 0.2;
    inputWeight2[1] = 0.9;
    inputWeight2[2] = 0.5;
    hiddenWeight[0] = 0.3;
    hiddenWeight[1] = 0.5;
    hiddenWeight[2] = 0.9;

    for (int i = 0; i < 3; i++) {
        hiddenNeuron[i] = sigmoid((input1 * inputWeight1[i]) + (input2 * inputWeight2[i]));
        int count = i + 1;
        cout << "Hidden Neuron #" << count << ": " << hiddenNeuron[i] << endl;
    }

    for (int i = 0; i < 3; i++) {
        output += hiddenNeuron[i] * hiddenWeight[i];
    }
    output = sigmoid(output);

    cout << "Output: " << output << endl;
    return 0;
}


/// Perform sigmoid function
double sigmoid(double value)
{
    return 1 / (1 + (exp(-value)));
}
