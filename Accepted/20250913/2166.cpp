// BOJ - 2166 다각형의 면적

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<long long, long long> > v;
    for(int i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({v[0].first, v[0].second});

    double ans = 0;
    for(int i = 0; i < n; i++)
        ans += (v[i].first * v[i + 1].second - v[i + 1].first * v[i].second);

    printf("%.1lf\n", abs(ans) / 2);
}