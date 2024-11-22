from collections import deque

n, l, r = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfs(start_x, start_y, visited):
    queue = deque([start_x, start_y])
    data = [(start_x, start_y)]
    visited[start_x][start_y] = True
    total_sum = graph[start_x][start_y]

    while queue:
        x, y = queue.popleft()

        for dx, dy in directions:
            nx, ny = x+dx, y+dy

            if 0<=nx<n and 0<=ny<n and not visited[nx][ny]:
                diff = abs(graph[x][y] - graph[nx][ny])
                if l<= diff <= r:
                    visited[nx][ny] = True
                    queue.append((nx, ny))
                    data.append((nx, ny))
                    total_sum += graph[nx][ny]
    return data, total_sum

count = 0

while True:
    visited = [[False]*n for _ in range(n)]
    updated = False

    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                data, total_sum = bfs(i, j, visited)

                if len(data) > l:
                    updated = True
                    average = total_sum // len(data)
                    for x, y in data:
                        graph[x][y] = average
    if not updated:
        break
    count += 1

print(count)

'''
p. 353 / sol 542
1. (1, 1) 부터 시작
2. 인접 노드 탐색
3. 방문한 후에 노드의 [2] 값을 기준으로 비교
4. 만약에 그 값의 차가 l보다는 크거나 같고 r보다는 작거나 같다면
5. data 리스트에 보관. 좌표랑 값이랑 모두
6. 아니면 queue에서 제거
7. queue에 있는 것과 모두 비교했을 때 조건이 만족을 안했다면 지금까지 올려진 data값의 평균을 계산하고 
data에 잇는 노드의 값을 모두 그 값으로 바꿔줌
8. 아직 방문하지 않은 좌표로 이동해서 2.과정부터 반복함.
9. 전체 노드 살펴본 후 data 평균으로 노드를 갱신한 경험이 1번이라도 잇으면 count 1증가
10. data 평균으로 갱신 경험이 없으면 종료하고 print(count)
'''

sol by book

from collections import deque

n, l, r = map(int, input().split())

graph = [list(map(int, input().split) for _ in range(n))]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

result = 0

# 특정 위치에서 출발하여 모든 연합을 체크한 뒤에 데이터 갱신
def process(x, y, index):
    # (x, y)의 위치와 연결된 나라 정보를 담는 리스트
    united = []
    united.append((x, y))

    q = deque()
    q.append((x, y))
    union[x][y] = index
    summary = graph[x][y]
    count = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0<=nx<n and 0<=ny< n and union[nx][ny] == -1:
                if l <= abs(graph[x][y] - graph[nx][ny]) <= r:
                    q.append((nx, ny))
                    union[nx][ny] = index
                    summary += graph[nx][ny]
                    count += 1
                    united.append((nx, ny))
    for i, j in united:
        graph[i][j] = summary // count
    return count


total_count = 0

while True:
    union = [[-1]*n for _ in range(n)]
    index = 0
    for i in range(n):
        for j in range(n):
            if union[i][j] == -1:
                process(i, j, index)
                index += 1
    if index == n*n:
        break
    total_count += 1

print(total_count)