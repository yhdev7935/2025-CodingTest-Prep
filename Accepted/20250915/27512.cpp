// BOJ - 27512 스네이크

#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int k = 0;
    if(n % 2 == 1 && m % 2 == 1) k = 1;
    cout << (n * m - k) << '\n';
}