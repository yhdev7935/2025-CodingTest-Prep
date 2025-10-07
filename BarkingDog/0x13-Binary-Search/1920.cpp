// BOJ - 1920 수 찾기

#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n; cin >> n;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    ll m; cin >> m;
    while(m--) {
        ll k; cin >> k;
        auto it = lower_bound(v.begin(), v.end(), k);
        if (it != v.end() && *it == k) cout << "1\n";
        else cout << "0\n";
    }
}