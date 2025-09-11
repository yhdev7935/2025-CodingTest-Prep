// BOJ - 2104 부분배열 고르기

// 모든 부분배열을 기준으로 생각하지 말고, 배열의 각 원소 A[i]를 기준으로 생각

// 만약 A[i]가 어떤 부분배열의 최솟값이라면, 그 부분배열의 점수는 (부분배열의 합) × A[i]가 됩니다.
// 이 점수를 최대로 만들려면, A[i]를 최솟값으로 가지면서 좌우로 최대한 확장한 부분배열을 찾아야 합니다.

// "최대한 확장한다"는 것은 무슨 의미일까요? 바로 A[i]보다 더 작은 값을 만나기 직전까지 확장하는 것입니다.

// As a result, 모든 i에 대해, A[i]를 최솟값으로 갖는 가장 큰 부분배열을 찾고, 그 점수를 계산하여 최댓값을 갱신한다.
// 각 A[i]에 대해 "왼쪽에서 가장 먼저 나타나는 A[i]보다 작은 원소" 와 "오른쪽에서 가장 먼저 나타나는 A[i]보다 작은 원소" 를 찾아야 합니다.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> v;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }
    vector<long long> acc(n + 1, 0);

    acc[0] = 0;
    for(int i = 0; i < n; i++) acc[i + 1] = acc[i] + v[i];

    long long res = 0;
    stack<int> stk;
    for(int i = 0; i < n; i++) {
        while(!stk.empty() && v[stk.top()] >= v[i]) {
            int k = stk.top(); stk.pop();
            int j = stk.empty() ? -1 : stk.top();
            res = max(res, v[k] * (acc[i] - acc[j + 1]));
            // [j , k , i]    v[j](왼쪽 경계) < v[k] > v[i](오른쪽 경계)
        }
        stk.push(i);
    }

    while(!stk.empty()) {
        int k = stk.top(); // [k, inf)
        stk.pop();

        int j = stk.empty() ? -1 : stk.top();
        res = max(res, v[k] * (acc[n] - acc[j + 1]));
    }

    cout << res << '\n';
}