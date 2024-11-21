from collections import deque

n, k = map(int, input().split())
data = []
virus_info = []

for i in range(n):
    row = list(map(int, input().split()))
    data.append(row)
    if j in range(n):
        if row[j] !=0:
            virus_info.append((row[j], 0, i, j))

virus_info.sort()
queue = deque(virus_info)

# 입력: s초 후에 확인할 위치
s, target_x, target_y = map(int, input().split())

# 방향벡터 (상, 하, 좌, 우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# BFS 수행
while queue:
    virus, time, x, y = queue.popleft()
    
    # s초가 지나면 종료
    if time == s:
        break

    # 인접한 4칸으로 확산
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < n:
            if data[nx][ny] == 0:  # 빈 칸인 경우만 확산
                data[nx][ny] = virus
                queue.append((virus, time + 1, nx, ny))

# 결과 출력 (s초 후의 값)
print(data[target_x - 1][target_y - 1])


#book
from collections import deque

n, k = map(int, input().split())
graph = []
data = []

for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(n):
        if graph[i][j] != 0:
            data.append((graph[i][j], 0, i, j))

data.sort()
q = deque(data)

target_s, target_x, target_y = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

while q:
    virus, s, x, y = q.popleft()
    if s == target_s:
        break

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < n and 0 <= ny < n:
            if graph[nx][ny] == 0:  # 빈 칸인 경우만 확산
                graph[nx][ny] = virus
                q.append((virus, s+1, nx, ny))

print(graph[target_x-1][target_y-1])
