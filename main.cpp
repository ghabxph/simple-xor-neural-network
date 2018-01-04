#include "declarations.h"

using namespace std;

/// --------------------------------
/// Application's entry point
/// ````````````````````````````````
int main()
{
    NeuralNetworkXor neuralNetworkXor;
    int i;

    i = 0;
    while (neuralNetworkXor.performXor(1,1) != 0 && i < 10000) {
        neuralNetworkXor.trainNetwork(1,1,0);
        cout << i << endl;
        i++;
    }

    cout << endl << "The XOR of 1 and 1 is: " << neuralNetworkXor.performXor(1,1) << endl;
    cout << endl << "The XOR of 0 and 0 is: " << neuralNetworkXor.performXor(0,0) << endl;
    cout << endl << "The XOR of 1 and 0 is: " << neuralNetworkXor.performXor(1,0) << endl;
    cout << endl << "The XOR of 0 and 1 is: " << neuralNetworkXor.performXor(0,1) << endl;


}
/// --------------------------------

