// BOJ - 7770 아즈텍 피라미드

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1 -> 5(1+4) -> 13(4+9) -> 25(9+16)

int main() {
    int n; cin >> n;
    int l = 1, b = 0;
    while(1) {
        b += l * l + (l - 1) * (l - 1);
        if(b > n) break;
        l++;
    }
    cout << (l - 1) << '\n';
}