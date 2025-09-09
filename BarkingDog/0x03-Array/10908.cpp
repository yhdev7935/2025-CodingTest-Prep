// BOJ - 10908 알파벳 개수

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;
    int ch[27] = {0, };
    for(int i = 0; i < s.size(); i++) ch[s[i] - 'a']++;
    for(int i = 0; i < 26; i++) cout << ch[i] << ' ';
    cout << '\n';
}