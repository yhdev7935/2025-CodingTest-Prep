# BOJ 11720 - 숫자의 합

n, s = int(input()), 0
k = input()
for t in k:
    s += int(t)
print(s)