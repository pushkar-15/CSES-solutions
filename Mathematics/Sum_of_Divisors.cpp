#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;


/* https://cp-algorithms.com/algebra/divisors.html#sum-of-divisors */


long long SumOfDivisors(long long num) {
    long long total = 1;

    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);

            long long sum = 0, pow = 1;
            do {
                sum += pow;
                pow *= i;
            } while (e-- > 0);
            total *= sum;
        }
    }
    if (num > 1)
        total *= (1 + num);

    return total;
}

int main() {
    int n;
    cin >> n;

    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans += SumOfDivisors(i) % MOD;
    }

    cout << ans;
}