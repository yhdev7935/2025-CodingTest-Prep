// BOJ - 1937 욕심쟁이 판다

// 500 * 500 = 25k
// 25k * 25k = 0.625b (BFS 불가)

// 2차원 배열에서 가장 긴 증가하는 지렁이 찾기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 501
#define ll long long int

using namespace std;

struct p {
    int x, y, v;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;
int isRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}
int cmp(p a, p b) {
    return a.v < b.v;
}
int main() {
    cin >> n;
    int dp[MAXN][MAXN] = {0, }, arr[MAXN][MAXN] = {0, };

    vector<p> v;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            int k; cin >> k;
            arr[i][j] = k; dp[i][j] = 1;
            v.push_back({i, j, k});
        }

    sort(v.begin(), v.end(), cmp);

    for(p cur : v) {
        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if(!isRange(nx, ny)) continue;
            if(cur.v < arr[nx][ny]) dp[nx][ny] = max(dp[nx][ny], dp[cur.x][cur.y] + 1);
        }
    }

    int maxv = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            maxv = max(maxv, (dp[i][j]));

    cout << maxv << '\n';
}