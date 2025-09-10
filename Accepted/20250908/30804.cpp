// BOJ - 30804 과일 탕후루

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int d[10] = {0, };
int chksz() {
    int cnt = 0;
    for(int i = 0; i <= 9; i++) cnt += !!d[i];
    return cnt;
}
int main() {
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }

    int a = 0, b = 0, ans = 0;
    while(b < n) {
        d[v[b]]++;
        while(chksz() >= 3) {
            d[v[a]]--;
            a++;
        }
        ans = max(ans, b++ - a + 1);
    }
    cout << ans << '\n';
}