// BOJ - 2230 수 고르기

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());

    ll s = 0, ans = v[v.size() - 1] - v[0];
    for(ll e = 0; e < n; e++) {
        while(s < n && v[e] - v[s] >= m)
            ans = min(ans, v[e] - v[s++]);
    }

    cout << ans << '\n';
}