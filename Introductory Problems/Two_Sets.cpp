#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; 
    cin >> n;
    ll sum = n * (n + 1) / 2;

    if (sum % 2) {
        cout << "NO\n";
    }
    
    else{
        cout << "YES\n";
        sum /= 2;

        vector<int> s1, s2;
        for (int i = n; i > 0; i--) {
            if (i <= sum) {
                sum -= i;
                s1.push_back(i);
            } else {
                s2.push_back(i);
            }
        }


        cout << s1.size() << "\n";
        for (int x : s1) cout << x << " ";
        cout << "\n";
        cout << s2.size() << "\n";
        for (int x : s2) cout << x << " ";
        cout << "\n";
    }
}