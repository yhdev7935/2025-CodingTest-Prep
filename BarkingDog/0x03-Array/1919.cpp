// BOJ  - 1919 애너그램 만들기

#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int ch[27] = {0, }, ch2[27] = {0, };
    for(int i = 0; i < a.size(); i++) ch[a[i] - 'a']++;
    for(int i = 0; i < b.size(); i++) ch2[b[i] - 'a']++;
    int cnt = 0;
    for(int i = 0; i < 27; i++) cnt += abs(ch[i] - ch2[i]);
    cout << cnt << '\n';
}