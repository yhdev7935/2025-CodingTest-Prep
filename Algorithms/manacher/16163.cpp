// BOJ - 16163 #15164번_제보 (Manacher's Algorithm 연습문제)
// 유형 2. 부분 문자열 중 회문 개수 찾기 (16163 번)

// 유형 2는 유형 1과 다르게 가장 긴 팰린드롬만 찾는 게 아니라 숨어있는 더 작은 팰린드롬들도 같이 찾아야 합니다.
// 예시) abacaba 는 중심 'c'를 공유하는 팰린드롬은 총 몇 개인가요? -> c, aca, bacab, abacaba -> len((L + 1) / 2)
// 예시) cabbac 는 중심 'c'를 공유하는 팰린드롬은 총 몇 개인가요? -> bb, abba, cabbac -> -> len(L / 2)
// L / 2도 C++에서는 (L + 1) / 2로 하면 됨.
// 정리: L 길이의 팰린드롬은 (L + 1) / 2 개의 팰린드롬을 의미하기도 합니다.

// manacher's 에 따라 배열 a의 모든 a[i]에 대해서 위 정리를 사용하면 됩니다.

#include <iostream>
#include <string>
#define ll long long int
#define MAXN 2000001
#define INF 0x7fffffffffff

using namespace std;

int a[MAXN * 2 + 2], n;
int isR(int x) {
    return 0 <= x && x < n;
}
int main() {
    // # concatentation
    string t_ss, ss = "#"; cin >> t_ss;
    for(char ch : t_ss) { ss.append(string(1, ch)); ss.append("#"); }

    n = ss.size();

    int c = -1, r = -1; 
    for(int i = 0; i < n; i++) {
        if(i < r) a[i] = min(a[2 * c - i], r - i);

        while(isR(i - (a[i] + 1)) && isR(i + (a[i] + 1)) && ss[i - (a[i] + 1)] == ss[i + (a[i] + 1)]) a[i]++;
        if(i + a[i] > r) r = i + a[i], c = i;
    } 

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += ((a[i] + 1) / 2);
    }
    cout << ans << '\n';
}