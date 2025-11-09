import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
gph = [[] for _ in range(n + 1)]
a, b = map(int, input().split())

m = int(input())
for _ in range(m):
    f, t = map(int, input().split())

    gph[f].append(t)
    gph[t].append(f)

queue = deque([a])
visited = [0] * (n + 1)
visited[a] = 1

while queue:
    front = queue.popleft()
    for nx in gph[front]:
        if visited[nx]: continue

        visited[nx] = visited[front] + 1
        queue.append(nx)

print((visited[b] - 1) if visited[b] else -1)