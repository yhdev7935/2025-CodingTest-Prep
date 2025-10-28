# BOJ 12891 - DNA 비밀번호

import sys
input = sys.stdin.readline

dd = {'A': 0, 'C': 1, 'G': 2, 'T': 3}

s, p = map(int, input().split())
dna = input().strip()
mnm = list(map(int, input().split()))
cur = [0] * 4

for i in range(0, p):
    cur[dd[dna[i]]] += 1

st, ed = 0, p # [s, e)
ans = 0
illegal = 0

if cur[0] >= mnm[0] and cur[1] >= mnm[1] and cur[2] >= mnm[2] and cur[3] >= mnm[3]:
    ans += 1

while ed < s:

    if dna[ed] in dd:
        cur[dd[dna[ed]]] += 1
    
    if dna[st] in dd:
        cur[dd[dna[st]]] -= 1

    if cur[0] >= mnm[0] and cur[1] >= mnm[1] and cur[2] >= mnm[2] and cur[3] >= mnm[3]:
        ans += 1

    st += 1; ed += 1

print(ans)
