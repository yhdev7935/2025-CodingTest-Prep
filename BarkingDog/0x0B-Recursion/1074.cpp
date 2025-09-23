// BOJ - 1074 Z

#include <iostream>

using namespace std;

int f(int n, int r, int c) {
    if(n == 0) return 0;
    int h = 1 << (n - 1);
    if(r < h && c < h) return f(n - 1, r, c);
    if(r < h && c >= h) return h * h + f(n - 1, r, c - h);
    if(r >= h && c < h) return 2 * h * h + f(n - 1, r - h, c);
    return 3 * h * h + f(n - 1, r - h, c - h);
}
int main() {
    int n, r, c; cin >> n >> r >> c;
    cout << f(n, r, c) << '\n';
}