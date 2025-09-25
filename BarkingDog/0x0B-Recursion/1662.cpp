// BOJ - 1662 압축

#include <iostream>
#include <stack>
#define ll long long int

using namespace std;

int main() {
    string s; cin >> s;
    stack<pair<ll, ll> > stk;
    // {length, last number}
    for(char ch : s) {
        if(ch == ')') {
            ll cnt = 0;
            while(!stk.empty() && stk.top().first != -1) { cnt += stk.top().first; stk.pop(); }
            stk.pop();
            cnt *= stk.top().second; stk.pop();
            stk.push({cnt, 0});
        }
        else if(ch == '(') stk.push({-1, -1});
        else {
            int k = 0;
            //if(!stk.empty() && stk.top().first != -1) { k = stk.top().first; stk.pop(); };
            stk.push({k + 1, ch - '0'});
        }
    }
    // 1      {1, 1}
    // 1(     {1, 1}, {-1, -1}
    // 1(9    {1, 1}, {-1, -1}, {1, 9}
    // 1(9)   {1, 1}, {-1, -1}, cnt = 1


    ll len = 0;
    while(!stk.empty()) { len += stk.top().first; stk.pop(); }
    cout << len << '\n';
}