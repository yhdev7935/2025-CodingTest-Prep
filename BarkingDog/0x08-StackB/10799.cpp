// BOJ - 10799 쇠막대기

#include <iostream>
#include <string>

using namespace std;

int main() {
    string ss; cin >> ss; int p = 0, res = 0;
    for(int i = 0; i < ss.size(); i++) {
        if(i < ss.size() - 1 && ss[i] == '(' && ss[i + 1] == ')') res += p, i++;
        else if(ss[i] == '(') p++;
        else if(ss[i] == ')') {
            res++; p--;
        }
    }

    cout << (res + p) << '\n';
}