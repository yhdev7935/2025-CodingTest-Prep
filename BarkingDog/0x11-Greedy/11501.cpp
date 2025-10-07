// BOJ - 11501 주식

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

void tc() {
    ll n; cin >> n;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        ll k; cin >> k; v.push_back(k);
    }
    reverse(v.begin(), v.end());

    ll high = 0, cnt = 0, sum = 0, ans = 0;
    for(ll k : v) {
        if(k > high) {
            ans += (cnt * high - sum);
            high = k, cnt = 1, sum = k;
        }
        else cnt++, sum += k;
    }
    ans += (cnt * high - sum);

    cout << ans << '\n';
}

int main() {
    ll t; cin >> t;
    while(t--) tc();
}