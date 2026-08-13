// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true
// Problem     StringStream
// Difficulty  Easy
// Subdomain   Strings
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-13, 10:24 p.m.
// ──────────────────────────────────────────────────

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> result;
    int num;
    char ch;

    while (ss >> num) {
        result.push_back(num);
        ss >> ch;
    }

    return result;
}

int main() {
    string str;
    cin >> str;

    vector<int> integers = parseInts(str);

    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
