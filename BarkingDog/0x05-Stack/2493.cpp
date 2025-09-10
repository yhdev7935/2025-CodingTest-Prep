// BOJ - 2493 탑

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    stack<pair<int, int> > stk;
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        while(!stk.empty() && stk.top().second <= k) stk.pop();
        if(stk.empty()) cout << "0 ";
        else cout << stk.top().first << ' ';
        stk.push({i, k});
    }
}