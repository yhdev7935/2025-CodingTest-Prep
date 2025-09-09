// BOJ - 3273 두 수의 합

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v; set<int> s;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
        s.insert(k);
    }
    int x, ans = 0; cin >> x;
    for(int i = 0; i < v.size(); i++) {
        int k = v[i];
        if(v[i] != x - v[i] && s.find(x - v[i]) != s.end()) ans++;
    }
    cout << ans/2 << '\n';
}