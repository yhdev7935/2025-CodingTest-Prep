// BOJ - 18870 좌표 압축

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        a.push_back(k); b.push_back(k);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for(int k : a) {
        cout << lower_bound(b.begin(), b.end(), k) - b.begin() << ' ';
    }
    cout << '\n';
}