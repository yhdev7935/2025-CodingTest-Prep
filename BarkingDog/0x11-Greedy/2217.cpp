// BOJ - 2217 로프

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int ans = 0, minv = 0x7fffffff, cnt = 1;
    for(int k : v) {
        minv = min(minv, k);
        ans = max(ans, cnt * minv);
        cnt++;
    }

    cout << ans << '\n';
}