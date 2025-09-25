// BOJ - 15654 N과 M (5)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[9] = {0, }, c[9] = {0, }, n, m;
int arr[9] = {0, };

void f(int idx) {
    if(idx == m + 1) {
        for(int i = 1; i <= m; i++) cout << arr[c[i]] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(p[i]) continue;
        c[idx] = i; p[i] = 1;
        f(idx + 1);
        c[idx] = 0; p[i] = 0;
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    f(1);    
}