// BOJ - 3015 오아시스 재결합

#include <iostream>
#include <stack>

using namespace std;

int main() {
    long long n, cnt = 0; cin >> n;
    stack<pair<int, int> > stk;
    for(int i = 1; i <= n; i++) {
        int k, t = 1; cin >> k;
        while(!stk.empty() && stk.top().first < k) { cnt += stk.top().second; stk.pop(); }
        if(!stk.empty() && stk.top().first == k) { t += stk.top().second; cnt += stk.top().second; stk.pop(); }

        if(!stk.empty()) cnt++; // [7, 5, 5]
        stk.push({k, t});
        //cout << cnt << ' ' << k << '\n';
    }

    cout << cnt << '\n';
}