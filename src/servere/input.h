#ifndef SRC_SERVERE_INPUT_H_
#define SRC_SERVERE_INPUT_H_

#include <fstream>
#include <vector>

using namespace std;

class InputData {
 public:
    static InputData& getInstance();
    int getNrServers();
    vector<int> getCalculPower();
    vector<int> getEnergyLimit();
    void readData(ifstream& inputFile);
    InputData(const InputData&) = delete;
    InputData& operator=(const InputData&) = delete;
 private:
    InputData();
    int nrServers;
    vector<int> calculPower;
    vector<int> energyLimit;
};

#endif  // SRC_SERVERE_INPUT_H_
