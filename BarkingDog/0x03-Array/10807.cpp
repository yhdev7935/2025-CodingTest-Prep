// BOJ - 10807 개수 세기

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v; map<int, int> m;
    for(int i = 0 ; i < n; i++) {
        int k; cin >> k;
        v.push_back(k); m[k]++;
    }
    int x; cin >> x;
    cout << m[x] << '\n';
}