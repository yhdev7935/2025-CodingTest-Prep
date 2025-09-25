// BOJ - 7795 먹을 것인가 먹힐 것인가

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void tc() {
    int n, m; cin >> n >> m;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        a.push_back(k);
    }
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        b.push_back(k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    for(int k : a) {
        cnt += lower_bound(b.begin(), b.end(), k) - b.begin();
    }

    cout << cnt << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) tc();
}