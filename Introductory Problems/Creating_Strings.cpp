#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* using inbuilt next_permutation() */


int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector<string> permutations;

    do {
        permutations.push_back(s);
    }
    while (next_permutation(s.begin(), s.end()));

    cout << permutations.size() << "\n";
    for (string x : permutations) cout << x << "\n";

}