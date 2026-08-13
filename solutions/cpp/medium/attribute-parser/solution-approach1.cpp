// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true
// Problem     Attribute Parser
// Difficulty  Medium
// Subdomain   Strings
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-13, 10:28 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    map<string, string> mp;
    vector<string> tags;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        // Closing tag
        if (s[1] == '/') {
            tags.pop_back();
            continue;
        }

        // Get tag name
        int pos = 1;
        while (s[pos] != ' ' && s[pos] != '>') {
            pos++;
        }

        string tag = s.substr(1, pos - 1);

        // Build complete tag path
        string path = "";

        for (int j = 0; j < tags.size(); j++) {
            if (j > 0)
                path += ".";
            path += tags[j];
        }

        if (!path.empty())
            path += ".";

        path += tag;

        tags.push_back(tag);

        // Read attributes
        while (pos < s.size() && s[pos] != '>') {

            while (pos < s.size() && s[pos] == ' ')
                pos++;

            if (s[pos] == '>')
                break;

            int equal = s.find('=', pos);

            // Remove spaces before '='
            int endAttr = equal;
            while (endAttr > pos && s[endAttr - 1] == ' ')
                endAttr--;

            string attribute = s.substr(pos, endAttr - pos);

            int firstQuote = s.find('"', equal);
            int secondQuote = s.find('"', firstQuote + 1);

            string value = s.substr(
                firstQuote + 1,
                secondQuote - firstQuote - 1
            );

            mp[path + "~" + attribute] = value;

            pos = secondQuote + 1;
        }
    }

    // Queries
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);

        if (mp.find(query) != mp.end())
            cout << mp[query] << endl;
        else
            cout << "Not Found!" << endl;
    }

    return 0;
}
