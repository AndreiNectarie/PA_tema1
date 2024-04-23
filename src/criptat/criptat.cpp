#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <list>
#include <chrono>

using namespace std;

bool canAppend(const unordered_map<char, int>& passwordFreq, int passwordLen, const string& word, const vector <pair<string, int>>& wordsFreq){
    unordered_map<char, int> wordFreq = passwordFreq;
    for (char c : word) {
        wordFreq[c]++;
    }
    for (auto& [c, freq] : wordFreq) {
        if (freq > (passwordLen + word.size()) / 2) {
            // there is a dominant letter
            return true;
        }
    }
    return false;
}

string getWord(vector <pair<string, int>>& wordsFreq) {
    int size = wordsFreq.size();
    for (auto& [word, freq] : wordsFreq) {
        if (freq == 0) {
            return word;
        }
    }
    return "";
}

int backtrack(vector <pair<string, int>>& wordsFreq, int idx, int& passLength, unordered_map<char, int>& passwordFreq, chrono::high_resolution_clock::time_point start, double timeLimit) {
    auto now = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration<double>(now - start).count();
    if (elapsed > timeLimit) {
        // If the time limit has been reached, return the current result
        return passLength;
    }
    int res = passLength;
    if(idx == wordsFreq.size()){
        return res;
    }
    for (auto& [currWord, freq] : wordsFreq) {
        if (freq) {
            continue;
        }
        if (canAppend(passwordFreq, passLength, currWord, wordsFreq) || idx == 0) {
            freq = true;
            idx++;
            for (char c : currWord) {
                passwordFreq[c]++;
            }
            passLength += currWord.size();
            res = max(res, backtrack(wordsFreq, idx, passLength, passwordFreq, start, timeLimit));
            idx--;
            freq = false;
            for (char c : currWord) {
                passwordFreq[c]--;
            }
            passLength -= currWord.size();
        }
    }
    return res;
}


int main() { 
    auto start = chrono::high_resolution_clock::now();
    int n;
    ifstream in("criptat.in");
    ofstream out("criptat.out");

    in >> n;
    vector <pair<string, int>> wordFreq;
    for (int i = 0; i < n; i++) {
        string word;
        in >> word;
        wordFreq.emplace_back(word, 0);
    }
    // sort the words by length
    sort(wordFreq.begin(), wordFreq.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first.size() > b.first.size();
    });
    string password = "";
    unordered_map<char, int> passwordFreq(26);
    for(int i = 0; i < 26 ; i++){
        passwordFreq['a' + i] = 0;
    }
    int idx = 0;
    double timeLimit = 1.93;
    int passLength = 0;
    out << backtrack(wordFreq, idx, passLength, passwordFreq, start, timeLimit) << endl;
    return 0;
}
