#include <vector>
#include <fstream>
#include "input.h"

using namespace std;

InputData::InputData() {
}

InputData& InputData::getInstance() {
    static InputData instance;
    return instance;
}



void InputData::readData(ifstream& inputFile) {
    inputFile >> nrServers;
    calculPower.resize(nrServers);
    energyLimit.resize(nrServers);
    for (int i = 0; i < nrServers; i++) {
        inputFile >> calculPower[i];
    }
    for (int i = 0; i < nrServers; i++) {
        inputFile >> energyLimit[i];
    }
    inputFile.close();
}
int InputData::getNrServers() {
    return nrServers;
}
vector<int> InputData::getCalculPower() {
    return calculPower;
}
vector<int> InputData::getEnergyLimit() {
    return energyLimit;
}