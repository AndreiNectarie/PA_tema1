#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void read(int *n, int *k, int v[]) {
    ifstream in("oferta.in");
    in >> *n >> *k;
    for (int i = 0; i < *n; i++) {
        in >> v[i];
    }
    in.close();
}
void solve(int n, int k, int v[], ofstream &fileOut) {
    double totalSum = 0;
    vector<double> minSum(n + 1, 0);   // decalaj de un elem
    for (int i = 1; i <= n; i++) {
        minSum[i] = minSum[i-1] + v[i-1];
        if (i == 1) {
            continue;
        }
        // this block of code only if we have more than 2 elements
        double sum1 = double(v[i-1] + v[i-2] - min(v[i-1], v[i-2]) / 2.0);
        minSum[i] = min(minSum[i], minSum[i - 2] + sum1);
        if (i == 2) {
            continue;
        }
        double sum2 = double(v[i-1] + v[i-2] + v[i-3]
                                - min(v[i-1], min(v[i-2], v[i-3])));
        // this block of code only if we have more than 3 elements
        minSum[i] = min(minSum[i], minSum[i - 3] + sum2);
    }
    fileOut << fixed << minSum[n] << endl;
}
int main() {
    ofstream fileOut("oferta.out");
    int n, k;
    int v[10001];
    read(&n, &k, v);
    solve(n, k, v, fileOut);
    return 0;
}
