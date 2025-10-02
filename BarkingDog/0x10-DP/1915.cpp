// BOJ - 1915 가장 큰 정사각형

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1001

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int arr[MAXN][MAXN] = {0, };
    int maxv = 0;

    for(int i = 0; i < n; i++) {
        string ss; cin >> ss;
        for(int j = 0; j < m; j++) {
            arr[i][j] = ss[j] - '0';
            maxv = max(maxv, arr[i][j]); // 최솟값 1 나올 수 있나
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int minv = min({arr[i - 1][j - 1], arr[i - 1][j], arr[i][j - 1]});
            if(arr[i][j] && minv != 0) arr[i][j] = minv + 1;
            maxv = max(maxv, arr[i][j]);
        }
    }

    cout << (maxv * maxv) << '\n';

}