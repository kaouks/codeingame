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
    
     

   for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < width; j++) 
            if(grid[i][j] != "."){
            
            int hasRightNeighbor = 0;
            int hasBottomNeighbor = 0;
            
            cout << j << " " << i << " ";
            
            
            for(int k = j+1; k < width; k++)
                if(grid[i][k] == "0"){
                    cout << k << " " << i << " ";
                    hasRightNeighbor = 1;
                    break;
                }
                
            if(!hasRightNeighbor)
                cout << "-1 -1 ";
            
            
            for(int k = i+1; k < height; k++)
                if(grid[k][j] == "0"){
                    cout << j << " " << k << " ";
                    hasBottomNeighbor = 1;
                    break;
                }
                
            if(!hasBottomNeighbor)
                cout << "-1 -1 ";
            
            cout << endl;
        }
        
    }
    
}
