// BOJ - 7579 앱

#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> mem, cst;
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        mem.push_back(k);
    }
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        cst.push_back(k);
    }

    // dp[cost] = "비활성화 비용 cost일 때 절약할 수 있는 메모리"
    ll dp[10001] = {0, };
    
    for(int i = 0; i < cst.size(); i++) {
        int cost = cst[i], memory = mem[i];
        for(int c = 10000; c >= cost; c--)
            dp[c] = max(dp[c], dp[c - cost] + memory);
    }

    for(int i = 0; i < 10001; i++)
        if(dp[i] >= m) {
            cout << i << '\n';
            break;
        }
    return 0;
}