// BOJ - 1863 스카이라인 쉬운거

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, res = 0; cin >> n;
    stack<int> stk;
    while(n--) {
        int _, k; cin >> _ >> k;
        while(!stk.empty() && stk.top() > k) {
            stk.pop(); res++;
        }
        if(!stk.empty() && stk.top() == k) stk.pop();
        if(k != 0) stk.push(k);
    }
    cout << (res + stk.size()) << '\n';
}