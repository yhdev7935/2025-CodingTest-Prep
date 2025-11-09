import sys
from collections import deque
input = sys.stdin.readline

n, l, r = map(int, input().split())
arr = [list(map(int, input().strip().split())) for _ in range(n)]

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def isRange(x, y, n):
    return 0 <= x and x < n and 0 <= y and y < n

def bfs():
    global arr, n, l, r, dx, dy
    visited = [[False] * n for _ in range(n)]

    changed = False

    for cx in range(n):
        for cy in range(n):
            if visited[cx][cy]: continue

            queue = deque()
            queue.append((cx, cy))
            visited[cx][cy] = True
            component = [(cx, cy)]
            total = arr[cx][cy]

            while queue:
                x, y = queue.popleft()
                for i in range(4):
                    nx, ny = x + dx[i], y + dy[i]
                    if not isRange(nx, ny, n): continue
                    if visited[nx][ny]: continue

                    diff = abs(arr[nx][ny] - arr[x][y])
                    if not (l <= diff <= r): continue

                    visited[nx][ny] = True
                    queue.append((nx, ny))
                    component.append((nx, ny))
                    total += arr[nx][ny]

            if len(component) > 1:
                avg = total // len(component)
                for x, y in component:
                    if arr[x][y] != avg:
                        changed = True
                        arr[x][y] = avg

    return changed

result = 0

while True:
    if not bfs():
        break
    result += 1

print(result)

