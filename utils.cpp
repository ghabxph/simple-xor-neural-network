/**
 * Copyright 2017 ghabxph(c)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

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

