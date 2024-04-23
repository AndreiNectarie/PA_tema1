#include <fstream>
#include <iostream>

using namespace std;

long long puteri2[100001];
long long puteri3[100001];

#define MOD 1000000007

long long mypow(int base, int power) {
    return (base == 2) ? puteri2[power] : puteri3[power];
}

void generate_powers() {
    puteri2[0] = 1;
    puteri3[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        puteri2[i] = (puteri2[i - 1] * 2) % MOD;
        puteri3[i] = (puteri3[i - 1] * 3) % MOD;
    }
}

int main() {
    ifstream in("colorare.in");
    ofstream out("colorare.out");

    if (!in.is_open() || !out.is_open()) {
        cout << "File not found";
        return -21;
    }

    int nr_sequences;
    long long result = 0;
    int n;
    char orientation;
    bool firstH = true;
    bool firstV = true;
    generate_powers();

    in >> nr_sequences;
    in >> n >> orientation;
    if (orientation == 'H') {
        result = (result + (2 * mypow(3, n)) % MOD) % MOD;
        firstH = false;
    } else if (orientation == 'V') {
        result = (result + (3 * mypow(2, n - 1)) % MOD) % MOD;
        firstV = false;
    }
    nr_sequences--;
    for (int i = 0; i < nr_sequences; i++) {
        in >> n >> orientation;
        if (orientation == 'H') {
            if (firstH) {
                result = (result * (2 * mypow(3, n - 1)) % MOD) % MOD;
                firstH = false;
                firstV = true;
            } else if (!firstH) {
                result = (result * mypow(3, n) % MOD) % MOD;
            }
        } else {
            if (firstV) {
                result = (result * mypow(2, n - 1) % MOD) % MOD;
                firstV = false;
                firstH = true;
            } else if (!firstV) {
                result = (result * mypow(2, n) % MOD) % MOD;
            }
        }
    }
    out << result << "\n";
    return 0;
}
