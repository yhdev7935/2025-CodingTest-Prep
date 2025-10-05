// BOJ - 11046 팰린드롬?? (Manacher's Algorithm 연습문제)
// 유형 3. Manacher's + Queries

// a, b입력이 들어왔을 때, S[a..b] 가 Palindrome인지 판단
// length >= 1M (full dp unavailable)
// Manacher's 의 배열 a를 가져와서 a와 b 사이 중심을 통해 팰린드롬인지 구분할 수 있음!

// 1213121 -> #1#2#1#3#1#2#1 (0, 2) -> (1, 5)
// 125521 -> #1#2#5#5#2#1 (0, 2) -> (1, 5)

#include <iostream>
#include <vector>
#define INF 0x7fffffffffff
#define ll long long int
#define MAXN 1000001

using namespace std;

int isR(int x, int n) {
    return 0 <= x && x < n;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> v; v.push_back(-1);
    vector<ll> a(MAXN * 2 + 2, 0);
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        v.push_back(k); v.push_back(-1);
    }
    n = v.size();

    ll r = -1, c = -1;
    for(ll i = 0; i < n; i++) {
        if(i < r) a[i] = min(a[2 * c - i], r - i);

        while(isR(i - (a[i] + 1), n) && isR(i + a[i] + 1, n) && v[i - (a[i] + 1)] == v[i + a[i] + 1]) a[i]++;
        if(i + a[i] > r) r = i + a[i], c = i;
    }

    ll m; cin >> m;
    while(m--) {
        ll s, e, len; cin >> s >> e; len = e - s + 1;
        s = (s - 1) * 2 + 1; e = (e - 1) * 2 + 1;
        ll m = (s + e) >> 1;
        if(a[m] >= len) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}