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
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways

    cin >> N >> L >> E; cin.ignore();
    int matrix[N][N] = {};
    int gatewayNodes[E];
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        matrix[N1][N2] = 1;
        matrix[N2][N1] = 1;
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        gatewayNodes[i] = EI;
    }
    
    int severed;
    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        severed = 0;
       
        for (int i = 0; i < E; i++){
            if( matrix[SI][gatewayNodes[i]] == 1) {
                matrix[SI][gatewayNodes[i]] = 0;
                severed = 1;
                cout << SI << " " << gatewayNodes[i]  << endl;
                break;
            }
        }
    
        if (!severed) { 
            for (int i = 0; i < E; i++)
                for (int j = 0; j < N, severed != 1; j++) 
                    if (matrix[gatewayNodes[i]][j] == 1) {
                        matrix[gatewayNodes[i]][j] = 0;
                        cout << gatewayNodes[i] << " " << j << endl;
                        severed = 1;
                    }
                
        }

    }
}
