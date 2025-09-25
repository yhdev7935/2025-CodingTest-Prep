// BOJ - 15650 N과 M (2)

#include <iostream>
#include <vector>

using namespace std;

int p[9] = {0, }, c[9] = {0, }, n, m;

void f(int idx, int prev) {
    if(idx == m + 1) {
        for(int i = 1; i <= m; i++) cout << c[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = prev + 1; i <= n; i++) {
        if(p[i]) continue;
        c[idx] = i; p[i] = 1;
        f(idx + 1, i);
        c[idx] = 0; p[i] = 0;
    }
}
int main() {
    cin >> n >> m;
    f(1, 0);    
}