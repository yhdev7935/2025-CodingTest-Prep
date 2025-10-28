# BOJ 2750 - 수 정렬하기

n, l = int(input()), []
for i in range(n):
    k = int(input())
    l.append(k)
for i in sorted(l):
    print(i)
