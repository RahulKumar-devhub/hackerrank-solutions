// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true
// Problem     Deque-STL
// Difficulty  Medium
// Subdomain   STL
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-15, 10:29 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> dq;

    for (int i = 0; i < n; i++) {

        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }

    cout << endl;
}

int main(){
  
    int t;
    cin >> t;

    while(t > 0) {
        int n, k;
        cin >> n >> k;

        int i;
        int arr[n];

        for(i = 0; i < n; i++)
            cin >> arr[i];

        printKMax(arr, n, k);
        t--;
    }

    return 0;
}
