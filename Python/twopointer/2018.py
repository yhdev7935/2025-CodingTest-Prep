# BOJ 2018 - 수들의 합 5

n = int(input())
s, e = 1, 1 # [s, e)
proc, ans = 0, 0
while e <= n:
    proc += e; e += 1
    while proc > n:
        proc -= s
        s += 1
    if proc == n:
        ans += 1
print(ans)