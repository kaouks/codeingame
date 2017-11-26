#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>


using namespace std;

class Point {
    public:
    double LON, LAT;
    
    Point()
  {
    LON = LAT = 0;
  }
    
    Point ( string x, string y){
        
        int pos = x.find(',');
        x[pos] = '.';
        LON = stod(x);
        pos = y.find(',');
        y[pos] = '.';
        LAT = stod(y);       
    }   
    
    static double distance ( Point A,  Point B);
        
};

class Defibrillator {
    public:
    string id, name, address, phone;
    Point location;
    
    Defibrillator (){};
    Defibrillator (string description);
};

Defibrillator::Defibrillator (string description){
    vector<string> infos;
    string info;
    stringstream ss(description);
    
    while (getline(ss, info, ';')){
        infos.push_back(info);
    }
    
    this-> id = infos[0];
    this-> name = infos[1];
    this-> address = infos[2];
    this-> phone = infos[3];
    Point p = Point(infos[4], infos[5]);
    this-> location = p;
    
}

double Point::distance (Point a, Point b){
    double x = (b.LON - a.LON)*cos((a.LAT + b.LAT)/2);
    double y = (b.LAT - a.LAT);
    double d = sqrt(pow(x,2) + pow(y,2)) * 6371;
    return d;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    
    vector <Defibrillator> defibrillators;
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        defibrillators.push_back(Defibrillator(DEFIB));
    }
    
    double min_d = numeric_limits<double>:: infinity();
    Point loc = Point(LON, LAT);
    Defibrillator def;
    
    for ( auto de:defibrillators){
        double dist = Point::distance (de.location, loc);
        if (dist < min_d){
            def = de;
            min_d = dist;
        }
    }
    

    cout << def.name << endl;
}
