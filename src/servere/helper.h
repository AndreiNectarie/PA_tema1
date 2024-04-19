// helper.h
#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <utility>

using namespace std;

double solve();
vector<pair<int, int>> initialize_servers_pair(int nrServers, vector<int> calculPower, vector<int> energyLimit);

#endif // HELPER_H