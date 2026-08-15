// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/exceptional-server/problem?isFullScreen=true
// Problem     Exceptional Server
// Difficulty  Medium
// Subdomain   Classes
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-15, 10:25 p.m.
// ──────────────────────────────────────────────────



		/* Enter your code here. */
        try {
    cout << Server::compute(A, B) << endl;
}
catch (bad_alloc& e) {
    cout << "Not enough memory" << endl;
}
catch (exception& e) {
    cout << "Exception: " << e.what() << endl;
}
catch (...) {
    cout << "Other Exception" << endl;
}

