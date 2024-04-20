#include <iostream>
#include <fstream>

using namespace std;

void read_input(int &n, int &m, int arrayA[], int arrayB[]) {
    ifstream in("compresie.in");

    if(!in.is_open()) {
        cerr << "Error opening file\n";
        exit(1);
    }
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> arrayA[i];
    }
    in >> m;
    for (int i = 0; i < m; i++) {
        in >> arrayB[i];
    }
    in.close();
}

int main() {
    int n = 0 , m = 0;
    int arrayA[300001], arrayB[300001];

    ofstream out("compresie.out");

    read_input(n, m, arrayA, arrayB);
    int i = 0, j = 0, sumA = 0, sumB = 0;
    int length = 0;
    while(i < n && j < m) {
        if(sumA == 0 && sumB == 0){
            if(arrayA[i] == arrayB[j]){
                i++;
                j++;
                length++;
                continue;
            }
            sumA += arrayA[i];
            sumB += arrayB[j];
        }
        if(sumA == sumB){
            length++;
            sumA = 0;
            sumB = 0;
            i++;
            j++;
        } else if(sumA < sumB){
            i++;
            sumA += arrayA[i];
        } else {
            j++;
            sumB += arrayB[j];
        }
    }
    if (length == 0 || i < n || j < m) {
        out << "-1\n";
    } else {
        out << length << "\n";
    }
}