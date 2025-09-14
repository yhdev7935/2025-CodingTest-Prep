// BOJ - 17499 수열과 시프트 쿼리

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }
    int m = 0;
    while(q--) {
        int cmd; cin >> cmd;
        if(cmd == 1) {
            int in, x; cin >> in >> x; in--;
            v[((in + m) % n)] += x;
        }
        else if(cmd == 2) {
            int s; cin >> s;
            m += (n - s);
        }
        else {
            int s; cin >> s;
            m += s;
        }
        m = m % n;
    }

    for(int i = 0; i < n; i++) cout << v[(i + m) % n] << ' '; cout << '\n';
}