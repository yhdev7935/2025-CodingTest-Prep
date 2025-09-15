// BOJ - 4949 균형잡힌 세상

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    
    while(1) {
        string ss; getline(cin, ss);
        if(ss == ".") break;

        stack<char> stk; int done = 1;
        for(char c : ss) {
            if(c == '(' || c == ')' || c == '[' || c == ']');
            else continue;

            if(c == ')') {
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else done = 0;
            }
            else if(c == ']') {
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else done = 0;
            }
            else stk.push(c);
        }
        if(!stk.empty()) done = 0;

        cout << (done ? "yes\n" : "no\n");
    }
}