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
    int n; // the number of temperatures to analyse
    int temperature = 9999;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        
        if ( abs(t) <= abs(temperature)){
            if(abs(t) == abs(temperature) && temperature > t)
                break;
                
            temperature = t;
        }
    }

    if ( n == 0)
        temperature = 0;
    cout << temperature << endl;
}
