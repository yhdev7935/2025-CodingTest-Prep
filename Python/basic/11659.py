# BOJ - 11659 구간 합 구하기 4

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr = [0] + arr
sarr = [0]
for i in range(1, n + 1):
    sarr.append(sarr[i - 1] + arr[i])
for _ in range(m):
    s, e = map(int, input().split())
    print(sarr[e] - sarr[s - 1])