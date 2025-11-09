# BOJ - 4889 안정적인 문자열

import sys
input = sys.stdin.readline

seq = 0
def tc():
    global seq
    seq += 1

    ss = input().strip()
    if '-' in ss: return 1

    stk, ans = [], 0
    for ch in ss:
        if ch == '}':
            if not stk:
                ans += 1
                stk.append('{')
            else:
                stk.pop()
        else:
            stk.append(ch)

    print(f'{seq}. {ans + len(stk) // 2}')


while True:
    if tc() == 1: break