#include <vector>
#include <climits>
#include <iostream>
#include <iomanip>
#include "input.h"


using namespace std;

vector<pair<int, int>> initialize_servers_pair(int nrServers, vector<int> calculPower, vector<int> energyLimit){
    vector<pair<int, int>> servers;
    for (int i = 0; i < nrServers; i++) {
        servers.emplace_back(calculPower[i], energyLimit[i]);
    }
    return servers;
}

double getMinPower(vector<pair<int, int>> servers, double mid){
    double min_power = __DBL_MAX__;
    for (size_t i = 0; i < servers.size(); i++) {
        double power = servers[i].first - abs(servers[i].second - mid);
        if (power < min_power) {
            min_power = power;
            //cout << "min_power: " << min_power << "\n";
        }
    }
    return min_power;
}

double getlow(vector<pair<int, int>> servers){
    double low = __DBL_MAX__;
    for (size_t i = 0; i < servers.size(); i++) {
        if(servers[i].second < low){
            low = servers[i].second;
        }
    }
    return low;
}

double gethigh(vector<pair<int, int>> servers){
    double high = -__DBL_MAX__;
    for (size_t i = 0; i < servers.size(); i++) {
        if(servers[i].second > high){
            high = double(servers[i].second);
        }
    }
    return high;
}

double solve(){
    InputData& data = InputData::getInstance();
    vector<pair<int, int>> servers = initialize_servers_pair(data.getNrServers(), data.getCalculPower(),
                                                  data.getEnergyLimit());
    
    double low = getlow(servers);
    double high = gethigh(servers);

    double mid;
    double maxMinPower = -__DBL_MAX__;
    double precision = 0.1;

    while(high - low >= precision){
        mid = low + (high - low) / 2;
        double min_power = __DBL_MAX__;
        min_power = getMinPower(servers, mid);
        double left = getMinPower(servers, mid - precision);
        double right = getMinPower(servers, mid + precision);
        if(min_power >= left && min_power >= right){
            maxMinPower = max(maxMinPower, min_power);
            break;
        }
        if(min_power > left) {
            low = mid;
        }
        else if(min_power > right){
            high = mid;
        }
    }
    
    return maxMinPower;
}
