// BOJ - 17298 오큰수

#include <iostream>
#include <stack>

using namespace std;

int seq[1000001] = {0, };
int main() {
    for(int i = 1; i <= 1000000; i++) seq[i] = -1;
    int n; cin >> n;
    stack<pair<int, int> > stk;
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        while(!stk.empty() && stk.top().first < k) {
            seq[stk.top().second] = k;
            stk.pop();
        }
        stk.push({k, i});
    }

    for(int i = 1; i <= n; i++) cout << seq[i] << ' ';
    cout << '\n';
}