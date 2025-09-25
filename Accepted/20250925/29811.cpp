// BOJ - 29811 지각하기 싫어

// idea 1: priority_queue + lazy deletion

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAXN 200001

using namespace std;

int status[MAXN] = {0, };
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int> >, bool(*)(pair<int, int>, pair<int, int>) > pq(cmp), pq2(cmp);

    for(int i = 1; i <= n + m; i++) {
        int k; cin >> k;
        if(i <= n) pq.push({k, i});
        else pq2.push({k, i});
        status[i] = k;
    }

    int cmdn; cin >> cmdn;
    while(cmdn--) {
        string cmd; cin >> cmd; 
        if(cmd == "U") {
            int x, y; cin >> x >> y;
            status[x] = y;
            if(x <= n) pq.push({y, x});
            else pq2.push({y, x});
        }
        else {
            // stale value elimination
            while(status[pq.top().second] != pq.top().first) pq.pop();
            while(status[pq2.top().second] != pq2.top().first) pq2.pop();

            cout << pq.top().second << ' ' << pq2.top().second << '\n';
        }
    }


}