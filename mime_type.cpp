#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    map <string, string> ext_table;
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        transform (EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        ext_table[EXT] = MT; 
    }
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        
        auto pos = FNAME.rfind('.');
        if (pos == string::npos)
            cout << "UNKNOWN" << endl;
        else {
            string ext = FNAME.substr(pos + 1);
            transform (ext.begin(), ext.end(), ext.begin(), ::tolower);
            
            if(ext_table.find(ext) != ext_table.end())
                cout << ext_table[ext] << endl;
            else
                cout << "UNKNOWN" << endl;
        }
    }
  
}
