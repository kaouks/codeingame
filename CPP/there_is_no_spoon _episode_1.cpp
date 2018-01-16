#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    string grid[width][height];
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        
        for (int j = 0; j < width; j++)
            grid[i][j] = line[j];
    }
    
     cout << " 0 0 -1 -1 -1 -1";

   for (int i = 0; i < height; i++) {
       int k;
        for (int j = 0; j < width; j++) 
            if(grid[i][j] == "0"){
            cout << j << " " << i << " ";
            for( k = j+1; k < width; k++)
                if(grid[i][k] == "0"){
                    cout << k << " " << i << " ";
                    break;
                }
   
            if(k == width)
                cout << "-1 -1 ";
            
            
            for( k = i+1; k < height; k++)
                if(grid[k][j] == "0"){
                    cout << j << " " << k << " ";
                    break;
                }
                
            if(k == height)
                cout << "-1 -1 ";
            
            cout << endl;
        }
        
    }
    
}
