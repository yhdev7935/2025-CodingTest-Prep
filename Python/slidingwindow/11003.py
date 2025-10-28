# BOJ - 11003 최솟값 찾기

from collections import deque

n, l = map(int, input().split())
arr = list(map(int, input().split()))

dq = deque() # (index, number)

for i in range(0, n): 
    while dq and dq[-1][1] > arr[i]:
        dq.pop()
    dq.append((i, arr[i]))
    while dq and dq[0][0] <= i - l:
        dq.popleft()
    print(dq[0][1], end = ' ')