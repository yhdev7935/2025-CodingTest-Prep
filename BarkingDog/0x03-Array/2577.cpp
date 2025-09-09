// BOJ - 2577 숫자의 개수

#include <iostream>
#include <string>

using namespace std;

int main() {
    long long int a, b, c, res = 0; cin >> a >> b >> c;
    res = a * b * c;
    string s = to_string(res);
    int ch[10] = {0, };
    for(int i = 0; i < s.size(); i++) ch[s[i] - '0']++;
    for(int i = 0; i <= 9; i++) cout << ch[i] << '\n';
}