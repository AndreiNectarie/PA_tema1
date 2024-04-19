#include <fstream>
#include <iostream>

using namespace std;

long long puteri2[100001];
long long puteri3[100001];

long long mypow(int base, int power){
    return (base == 2) ? puteri2[power] : puteri3[power];
}

void generate_powers(){
    puteri2[0] = 1;
    puteri3[0] = 1;
    for(int i = 1; i <= 100000; i++){
        puteri2[i] = (puteri2[i - 1] * 2) % 1000000007;
        puteri3[i] = (puteri3[i - 1] * 3) % 1000000007;
    }
}

int main() {

    ifstream in("colorare.in");
    ofstream out("colorare.out");

    if(!in.is_open() || !out.is_open()){
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
    in >> n >> orientation;                         // ca sa nu fie result = 0 si sa putem sa inmlutim result.
    if(orientation == 'H'){
        // prima orizontala => 2*3
        result = (result + (2 * mypow(3, n)) % 1000000007) % 1000000007;
        firstH = false;
    }
    else if(orientation == 'V'){
        // prima verticala => 3
        result = (result + (3 * mypow(2, n - 1)) % 1000000007) % 1000000007;
        firstV = false;
    }
    nr_sequences--;
    for(int i = 0; i < nr_sequences; i++) {
        in >> n >> orientation;
        if(orientation == 'H'){
            if(firstH){
                // prima orizontala din secventa => 2*3
                result = (result * (2 * mypow(3, n - 1)) % 1000000007) % 1000000007;
                firstH = false;
                firstV = true;
            }
            else if(!firstH){
                // orizontala => *3
                result = (result * mypow(3, n) % 1000000007) % 1000000007;
            }
        }
        else {
            if (firstV) {
                // prima verticala din secventa => 1 * 2^(n-1)
                result = (result * mypow(2, n - 1) % 1000000007) % 1000000007;
                firstV = false;
                firstH = true;
            }
            else if (!firstV) {
                // verticala => *2
                result = (result * mypow(2, n) % 1000000007) % 1000000007;
            }
        }
    }
    //cout <<nr_sequences << "\n";
    out << result << "\n";
    return 0;
}

/*int main(){
    ifstream in("colorare.in");
    ofstream out("colorare.out");

    if(!in.is_open() || !out.is_open()){
        cout << "File not found";
        return -21;
    }
    int nr_sequences;

    in >> nr_sequences;
    for(int i = 0; i < nr_sequences; i++){
        int n;
        char orientation;
        long long result = 0;
        in >> n >> orientation;
        if(n > 1000001){
            cout << "n is too big";
        }
    }
    return 0;
}*/