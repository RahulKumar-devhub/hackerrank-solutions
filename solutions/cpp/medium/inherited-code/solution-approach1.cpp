// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/inherited-code/problem?isFullScreen=true
// Problem     Inherited Code
// Difficulty  Medium
// Subdomain   Classes
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-14, 08:56 p.m.
// ──────────────────────────────────────────────────



/* Define the exception here */
class BadLengthException {
private:
    int length;

public:
    BadLengthException(int n) {
        length = n;
    }

    int what() {
        return length;
    }
};

