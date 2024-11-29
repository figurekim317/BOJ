from collections import deque

n, m = map(int, input().split())
map_data = [[*map(int, input())] for _ in range(n)]

steps = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    while queue:
        x, y = queue.popleft()
        for step in steps:
            nx = x + step[0]
            ny = y + step[1]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if map_data[nx][ny] == 0:
                continue
            if map_data[nx][ny] == 1:
                map_data[nx][ny] = map_data[x][y] + 1
                queue.append((nx, ny))
    return map_data[n-1][m-1]


from collections import deque

n, m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 미로찾기 영역을 벗어난 경우
            if nx < 0 or nx>=n or ny<0 or ny>=m:
                continue
            # 벽인 경우 무시
            if graph[nx][ny] == 0:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))
    return graph[n-1][m-1]

bfs(0,0)
print(graph)        