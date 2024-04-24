#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)


/* simulate using set for positions and multiset for lengths */


int main() {
    fastio;

    int x, n;
    cin >> x >> n;

    set<int> positions;
    multiset<int> lengths;

    positions.insert(0); positions.insert(x);
    lengths.insert(x - 0);

    for(int i=0; i<n; i++){
        int p; cin >> p;
        positions.insert(p);

        auto curr = positions.find(p);
        auto justLarger = positions.upper_bound(p);
        auto justSmaller = prev(curr);

        lengths.erase(lengths.find(*justLarger - *justSmaller));
        lengths.insert(*justLarger - *curr);
        lengths.insert(*curr - *justSmaller);

        cout << *(lengths.rbegin()) << " ";
    }
}