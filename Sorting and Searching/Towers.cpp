#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* only if just-greater-element than current element is placed on top, make a new tower */


int main() {
    int n;
    cin >> n;

    multiset<int> ms;
    while(n--){
        int x;
        cin >> x;

        auto justGreaterElement = ms.upper_bound(x);
        if(justGreaterElement != ms.end()) ms.erase(justGreaterElement);

        ms.insert(x);
    }

    std::cout << (int)ms.size();
}