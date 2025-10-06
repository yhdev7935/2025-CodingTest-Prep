// BOJ - 11047 동전 0

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        ll t; cin >> t;
        v.push_back(t);
    }
    reverse(v.begin(), v.end());
    ll cnt = 0;
    for(ll t : v) {
        cnt += (k / t);
        k %= t;
    }

    cout << cnt << '\n';
}

