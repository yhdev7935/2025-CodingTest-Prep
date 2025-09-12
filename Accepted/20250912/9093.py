t = int(input())
for _ in range(t):
    ss = input()
    ss = ss.split()
    for s in ss:
        print(s[::-1], end=' ')
    print()