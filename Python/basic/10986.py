import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [0] + list(map(int, input().split()))
sarr = [0]
cnt = [0] * (m + 1)

for i in range(1, n + 1):
    sarr.append(sarr[i - 1] + arr[i])
    cnt[sarr[i] % m] += 1

ans = 0
for i in range(0, m):
    if cnt[i] > 1:
        ans += (cnt[i] * cnt[i] - cnt[i]) // 2
print(cnt[0] + ans)