// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/bitset-1/problem?isFullScreen=true
// Problem     Bit Array
// Difficulty  Hard
// Subdomain   Other Concepts
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-13, 10:36 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long N, S, P, Q;
cin >> N >> S >> P >> Q;

const unsigned long long MOD = (1ULL << 31);

unsigned long long current = S;
unsigned long long previous = 0;
unsigned long long count = 0;

for (unsigned long long i = 0; i < N; i++) {

    if (i > 0 && (current == S || current == previous)) {
        break;
    }

    count++;

    previous = current;

    current = (current * P + Q) % MOD;
}

cout << count << endl;   
    return 0;
}
