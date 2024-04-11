#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector < int > cnt(26);
    for (char c: s)
        cnt[c - 'A']++;

    // check for odd frequencies
    int odd = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) {
            if (odd != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            } else {
                odd = i;
            }
        }
    }

    // construct palindrome
    string t1;
    for (int i = 0; i < 26; i++) {
        t1 += string(cnt[i] / 2, 'A' + i);
    }
    string t2(t1.rbegin(), t1.rend());
    if (odd != -1) t1 += (char)('A' + odd);
    cout << t1 << t2 << "\n";
}