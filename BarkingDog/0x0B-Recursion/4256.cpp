// BOJ - 4256  트리

// 전위, 중위 순회 순서를 알았을 때 -> 후위 순회 결과 구하기

#include <iostream>
#include <vector>

using namespace std;

vector<int> pre, in; 

void post_order(int s, int e, int pos) {
    for(int i = s; i < e; i++) {
        if(in[i] == pre[pos]) {
            post_order(s, i, pos + 1);
            post_order(i + 1, e, pos + 1 + i - s);
            cout << pre[pos] << ' ';
        }
    }
}
void tc() {
    int n; cin >> n;
    pre = vector<int>(n);
    in  = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];

    post_order(0, n, 0);
    cout << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) tc();
}