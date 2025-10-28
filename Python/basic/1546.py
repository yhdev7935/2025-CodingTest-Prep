# BOJ 1546 - 평균

n = int(input())
l = list(map(int, input().split()))
maxv, s = max(l), 0
for i in l:
    s += (i / maxv) * 100
print(s / len(l))