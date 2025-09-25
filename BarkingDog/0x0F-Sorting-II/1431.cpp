// BOJ - 1431 시리얼 번호

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(string a, string b) {
    if(a.size() == b.size()) {
        int suma = 0, sumb = 0;
        for(char ch : a) if('0' <= ch && ch <= '9') suma += (ch - '0');
        for(char ch : b) if('0' <= ch && ch <= '9') sumb += (ch - '0');
        if(suma == sumb) return a < b;
        return suma < sumb;
    }
    return a.size() < b.size();
}
int main() {
    vector<string> v;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string ss; cin >> ss;
        v.push_back(ss);
    }
    sort(v.begin(), v.end(), cmp);

    for(string ss : v) {
        cout << ss << '\n';
    }
}