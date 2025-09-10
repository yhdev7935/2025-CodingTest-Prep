// BOJ - 10773 제로

#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int n; cin >> n;
    while(n--) {
        int k; cin >> k;
        if(k == 0) s.pop();
        else s.push(k);
    }

    int cnt = 0;
    while(!s.empty()) {
        cnt += s.top();
        s.pop();
    }

    cout << cnt << '\n';
}