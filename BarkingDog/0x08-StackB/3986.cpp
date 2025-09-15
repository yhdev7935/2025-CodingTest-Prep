// BOJ - 3986 좋은 단어

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main() {
    int cnt = 0;
    int n; cin >> n;
    while(n--) {
        stack<char> stk;
        string ss; cin >> ss;

        for(char c : ss) {
            if(!stk.empty() && stk.top() == c) stk.pop();
            else stk.push(c);
        }

        if(stk.empty()) cnt++;
    }

    cout << cnt << '\n';
}