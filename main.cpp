#include "declarations.h"

using namespace std;

/// --------------------------------
/// Application's entry point
/// ````````````````````````````````
int main()
{
    /*
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
    */

    NeuralNetworkXor neuralNetworkXor;

    neuralNetworkXor.trainNetwork();

    return 1;
}
/// --------------------------------

