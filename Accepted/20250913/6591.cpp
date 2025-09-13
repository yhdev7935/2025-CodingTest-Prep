// BOJ - 6591 이항 쇼다운

#include <iostream>

using namespace std;

long long comb(long long n, long long k) {
    long long ans = 1; k = min(k, n - k);
    for(long long i = 0; i < k; i++)
        ans = ans * (n - i), ans = ans / (i + 1);
    return ans;
}
int main() {
    while(1) {
        long long a, b; cin >> a >> b;
        if(a == 0 && b == 0) break;

        cout << comb(a, b) << '\n';
    }

    return 0;
}