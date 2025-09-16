// BOJ - 33675 L-트리미노 타일링

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll powll(ll n, ll k) {
    ll res = 1;
    for(int i = 1; i <= k; i++) res *= n;
    return res;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n % 2) cout << "0\n";
        else {
            // n = 2 -> 2
            // n = 4 -> 2 x 2
            // n = 6 -> 2 x 2 x 2
            // 2^(n/2), btw n limits 100
            // python 추천 ㅋㅋㅋ
            cout << powll(2, n / 2) << '\n';
        }
    }
}