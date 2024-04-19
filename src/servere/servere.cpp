#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "input.h"
#include "helper.h"

using namespace std;

int main() {

    ifstream in("servere.in");
    ofstream out("servere.out");

    //ifstream in("input.in");
    //ofstream out("output.out");

    if(!in.is_open() || !out.is_open()){
        cout << "File not found";
        return -21;
    }
    // Read the input data
    InputData::getInstance().readData(in);
        
    out << setprecision(1) << fixed << solve() << endl;

    return 0;
}