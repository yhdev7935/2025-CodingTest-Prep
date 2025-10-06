// BOJ - 1026 보물

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        a.push_back(k);
    }
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        b.push_back(k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i] * b[i];

    cout << s << '\n';
}