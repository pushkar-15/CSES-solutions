#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* simulate using multiset */


int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> ticketPrices;
    while(n--) {
        int x; cin >> x;
        ticketPrices.insert(x);
    }
    
    while(m--){
        int x; cin >> x;
        auto upper = ticketPrices.upper_bound(x);

        if(upper == ticketPrices.begin()) 
            cout << -1 << endl;
        else{
            upper = prev(upper);
            cout << *upper << endl;
            ticketPrices.erase(upper);
        }
    }


}