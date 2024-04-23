#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int maxLength = 0;

bool isValid(const string& password) {
    vector<int> freq(26, 0);
    int len = password.size();
    
    for(char ch : password) {
        freq[ch - 'a']++;
    }
    
    for(int i = 0; i < 26; i++) {
        if(freq[i] > len / 2) {
            return true;
        }
    }
    
    return false;
}

void generatePasswords(const vector<string>& words, int idx, string& currentPassword) {
    if(isValid(currentPassword)) {
        maxLength = max(maxLength, (int)currentPassword.size());
    }
    
    if(idx == words.size() || currentPassword.size() >= maxLength) {
        return;
    }
    
    for(int i = idx; i < words.size(); i++) {
        currentPassword += words[i];
        generatePasswords(words, i + 1, currentPassword);
        currentPassword.erase(currentPassword.end() - words[i].size(), currentPassword.end());
    }
}

int main() {
    int n;
    
    ifstream in("criptat.in");
    ofstream out("criptat.out");
    
    in >> n;
    
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        in >> words[i];
    }
    
    string currentPassword = "";
    generatePasswords(words, 0, currentPassword);
    
    cout << maxLength << endl;
    
    return 0;
}
