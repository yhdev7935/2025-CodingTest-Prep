// BOJ - 17945 통학의 신

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// ax^2 + bx + c = 0
// x = (-b ± √(b² - 4ac)) / 2a

// Q: x^2 + 2ax + b = 0
// A: (-2a ± √(4a² - 4b)) / 2
int main() {
    int a, b; cin >> a >> b;
    int k1 = (-2 * a + (int) sqrt(4 * a * a - 4 * b)) / 2;
    int k2 = (-2 * a - (int) sqrt(4 * a * a - 4 * b)) / 2;
    if(k1 == k2) cout << k1 << '\n';
    else if(k1 < k2) cout << k1 << ' ' << k2 << '\n';
    else cout << k2 << ' ' << k1 << '\n';
}