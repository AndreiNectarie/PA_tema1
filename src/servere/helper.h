#ifndef SRC_SERVERE_HELPER_H_
#define SRC_SERVERE_HELPER_H_

#include <vector>

using namespace std;

double solve();
vector<pair<int, int>> initialize_servers_pair(
    int nrServers, vector<int> calculPower, vector<int> energyLimit);

#endif   // SRC_SERVERE_HELPER_H_
