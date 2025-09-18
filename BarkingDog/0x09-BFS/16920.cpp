// BOJ - 16920 확장 게임

#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#define ll long long
#define MAXN 1001

using namespace std;

ll n, m, p;
ll pi[10], arr[MAXN][MAXN];
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {-1, 1, 0, 0};
queue<pair<int, int> > q[10];
int isRange(ll x, ll y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
void bfs() {
    while(1) {
        bool moved = false;
        for(int i = 1; i <= p; i++) {
            for(int step = 0; step < pi[i]; step++) {
                int qs = (int)q[i].size();
                if(qs == 0) break;
                while(qs--) {
                    pair<int, int> t = q[i].front(); q[i].pop();
                    for(int j = 0; j < 4; j++) {
                        int nx = t.first + dx[j], ny = t.second + dy[j];
                        if(!isRange(nx, ny)) continue;
                        if(arr[nx][ny] != 0) continue;
                        arr[nx][ny] = i;
                        q[i].push({nx, ny});
                        moved = true;
                    }
                }
            }
        }
        if(!moved) break;
    }
}
int main() {
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++) cin >> pi[i];

    for(int i = 1; i <= n; i++) {
        string ss; cin >> ss;
        for(int j = 1; j <= m; j++) {
            if(ss[j - 1] == '.') arr[i][j] = 0;
            else if(ss[j - 1] == '#') arr[i][j] = -1;
            else {
                arr[i][j] = ss[j - 1] - '0';
                q[arr[i][j]].push({i, j});
            }
        }
    }

    bfs();

    int cnt[10] = {0, };
    for(int i = 1; i <= n; i++)
        for(int j = 1; j    <= m; j++)
            if(1 <= arr[i][j] && arr[i][j] <= 9)
                cnt[arr[i][j]]++;

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = 1; i <= p; i++)
        cout << cnt[i] << ' ';
    cout << '\n';

    return 0;
}