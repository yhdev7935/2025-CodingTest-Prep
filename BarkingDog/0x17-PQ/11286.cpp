// BOJ - 11286 절댓값 힙

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(int a, int b) {
    if(abs(a) == abs(b)) return a > b;
    return abs(a) > abs(b);
}
int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, bool(*)(int,int)> pq(cmp);
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        if(k == 0) {
            if(pq.size() == 0) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(k);
    }
}