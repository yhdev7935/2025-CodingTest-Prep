// BOJ - 30684 모르고리즘 회장 정하기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> v;
    for(int i = 1; i <= n; i++) {
        string ss; cin >> ss;
        if(ss.size() != 3) continue;
        v.push_back(ss);
    }
    sort(v.begin(), v.end());

    cout << v[0] << '\n';

}