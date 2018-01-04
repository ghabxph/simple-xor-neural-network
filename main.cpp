#include "declarations.h"

using namespace std;

/// --------------------------------
/// Application's entry point
/// ````````````````````````````````
int main()
{
    NeuralNetworkXor neuralNetworkXor;
    neuralNetworkXor.trainNetwork(1,1,0);
//    neuralNetworkXor.trainNetwork(0,0,0);
//    neuralNetworkXor.trainNetwork(1,0,1);
//    neuralNetworkXor.trainNetwork(0,1,1);
    return 1;
}
/// --------------------------------

