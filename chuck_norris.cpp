
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    
    // Generate the binary representation of the message
    string bitMessage;
    for (char c : MESSAGE)
    {
        for (int i = 0; i < 7; ++i)
        {
            c = c << 1;
            bitMessage += ((c >> 7) & 1) + '0';
        }
    }

    // Encode the message
    int i = 0;
    
    while (i < bitMessage.size()){
        if( bitMessage[i] == '0'){
            cout<< "00 ";
            while(bitMessage[i] == '0' && i < bitMessage.size()){
                cout << "0";
                i++;
            }
             if (i < bitMessage.size())
                cout << " ";
        }
        else {
            cout << "0 ";
            while(bitMessage[i] == '1' && i < bitMessage.size()){
                cout << "0";
                i++;
            }
            
            if (i < bitMessage.size())
                cout << " ";
        }
    }
    cout << endl;
}
