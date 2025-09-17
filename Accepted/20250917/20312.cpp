// BOJ - 20312 CPU 벤치마킹

#include <iostream>
#include <algorithm>
#define ll long long
#define MOD 1000000007

// a, a * b, a * b * c
//        b,     b * c
//                   c
//
// a , (a + 1) * b , ((a + 1) * b + 1) * c
// X , (X + 1) * b = Y , (Y + 1) * c ...
using namespace std;

int main() {
    ll n, sum = 0, prev = 0; cin >> n;
    for(ll i = 1; i < n; i++) {
        ll k; cin >> k;
        if(i == 1) sum = prev = k % MOD;
        else {
            prev = (((prev + 1) % MOD) * (k % MOD)) % MOD;
            sum = (sum % MOD + prev % MOD) % MOD;
        }
    }

    cout << sum << '\n';
}