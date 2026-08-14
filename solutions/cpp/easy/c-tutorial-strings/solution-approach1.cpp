// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/c-tutorial-strings/problem?isFullScreen=true
// Problem     Strings
// Difficulty  Easy
// Subdomain   Strings
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-14, 08:54 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    
    cin >> a >> b;
    
    cout << a.size() << " " << b.size() << endl;
    
    cout << a + b << endl;
    
    swap(a[0], b[0]);
    cout << a << " " << b << endl;
    
    return 0;
}
