// BOJ - 1182 부분수열의 합

#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll n, s, cnt = 0;
vector<ll> v;
void f(ll i, ll sum) {
    if(sum + v[i] == s) cnt++;
    if(i >= n - 1) return;
    f(i + 1, sum);
    f(i + 1, sum + v[i]);
}
int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        v.push_back(k);
    }

    f(0, 0);

    cout << cnt << '\n';
}