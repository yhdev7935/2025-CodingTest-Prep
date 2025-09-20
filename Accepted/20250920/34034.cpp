// BOJ - 34034 스트릭 채우기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAXN 200001

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n, m, k; cin >> n >> m >> k;

    vector<pair<int, int> > v;
    for(int i = 1; i <= n; i++) {
        int t; cin >> t;
        v.push_back({t, i});
    }

    sort(v.begin(), v.end(), cmp);

    int streak_cnt = 0; vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(streak_cnt + v[i].first - 1 > m) break;
        if(streak_cnt + ans.size() + v[i].first > k) break;

        streak_cnt += (v[i].first - 1);
        ans.push_back(i);
    }

    // 0000203000
    int need_streak = k - (streak_cnt + ans.size());
    if(need_streak + streak_cnt > m) cout << "-1\n";
    else {
        for(int t : ans) {
            pair<int, int> p = v[t];
            for(int r = 0; r < p.first - 1; r++) cout << "0 ";
            cout << p.second << ' ';
        }
        for(int r = 0; r < need_streak; r++) cout << "0 ";
        cout << "\n";
    }
    return 0;
}