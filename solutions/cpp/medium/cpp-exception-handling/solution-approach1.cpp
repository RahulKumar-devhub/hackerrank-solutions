// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/cpp-exception-handling/problem?isFullScreen=true
// Problem     Cpp exception handling
// Difficulty  Medium
// Subdomain   Debugging
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-16, 08:24 p.m.
// ──────────────────────────────────────────────────



void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
    }
    catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    cout << "returning control flow to caller" << endl;
}

