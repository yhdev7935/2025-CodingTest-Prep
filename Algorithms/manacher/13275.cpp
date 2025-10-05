// BOJ - 13275 가장 긴 팰린드롬 부분 문자열 (Manacher's Algorithm 연습문제)
// 유형 1. 부분 문자열 중 가장 긴 팰린드롬 길이 찾기 (13275 번)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAXN 100001

using namespace std;

int n;
int isR(int x) {
    return 0 <= x && x < n;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    // 홀수, 짝수 통일화
    string t_ss, ss = "#"; cin >> t_ss;
    for(char ch : t_ss) { ss.append(string(1, ch)); ss.append("#"); }

    n = ss.size();
    int a[MAXN * 2 + 2] = {0, }; // a[i]는 가공된 문자열 ss의 i번째 인덱스를 중심으로 하는 팰린드롬의 반지름을 저장
    int r = -1, c = -1; // r = 가장 오른쪽으로 멀리 뻗어있는 팰린드롬의 오른쪽 경계 인덱스, c = 그 중심 인덱스

    for(int i = 0; i < n; i++) {
        // i가 이전에 찾은 가장 긴 팰린드롬 (c, r) 내부에 있다면, 대칭 되는 점은 2 * c - i 입니다.
        int i_mirror = 2 * c - i;
        if(i < r) // 오우예스, 재활용 ㄱㄱ
            a[i] = min(a[i_mirror], r - i); // 이게 시간복잡도를 줄여준 원인입니다.
        
        // if(i >= r) 직접 해야함
        while(isR(i - (a[i] + 1)) && isR(i + a[i] + 1) && 
            ss[i - (a[i] + 1)] == ss[i + (a[i] + 1)])
                a[i]++;

        if(i + a[i] > r) r = i + a[i], c = i; // c, r 마지막에 업데이트
    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, a[i]);

    cout << ans << '\n';
}