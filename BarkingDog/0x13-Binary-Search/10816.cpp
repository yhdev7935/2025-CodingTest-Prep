// BOJ - 10816 숫자 카드 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    int m; cin >> m;
    while(m--) {
        int k; cin >> k;
        auto l = lower_bound(v.begin(), v.end(), k);
        auto u = upper_bound(v.begin(), v.end(), k);
        auto lv = l - v.begin();
        auto uv = u - v.begin();
        if(l != v.end() && v[lv] == k) cout << (uv - lv) << ' ';
        else cout << 0 << ' ';
    }
    cout << '\n';
}