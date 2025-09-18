// BOJ - 32713 숫자 POP

#include <iostream>
#include <set>
#define MAXN 5001

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int arr[5001] = {0, };
    set<int> uq_numbers;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        uq_numbers.insert(arr[i]);
    }

    int ans = 0;
    for(int uq : uq_numbers) {
        int s = 1, e, del = 0, cnt = 0;
        for(e = 1; e <= n; e++) {

            if(arr[e] == uq) cnt++;
            else del++;

            while(del > m) { // 초과!
                if(arr[s] == uq) cnt--;
                else del--;
                s++;
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << '\n';
}