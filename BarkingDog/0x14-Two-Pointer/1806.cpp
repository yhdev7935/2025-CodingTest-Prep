// BOJ - 1806 부분합

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main() {
    ll n, s; cin >> n >> s;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        v.push_back(k);
    }
    ll st = 0, sum = 0, ans = n + 1;
    for(ll ed = 0; ed < n; ed++) {
        sum += v[ed];
        while(st < n && sum >= s) {
            ans = min(ans, ed - st + 1);
            sum -= v[st++];
        }
    }

    if(ans == n + 1) cout << "0\n";
    else cout << ans << '\n';
}