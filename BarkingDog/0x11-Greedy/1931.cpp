// BOJ - 1931 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end(), cmp);
    
    int cur = 0, cnt = 0;
    for(pair<int, int> p : v) {
        if(cur <= p.first) {
            cnt++;
            cur = p.second;
        }
    }

    cout << cnt << '\n';
}