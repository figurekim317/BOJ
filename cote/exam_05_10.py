n, m = map(int, input().split())
graph = [[*map(int, input())] for _ in range(n)]

def dfs(x, y):
    if x <= -1 or x>=n or y<= -1 or y>=m:
        return False
    if graph[x][y] == 0:
        graph[x][y] = 1
        dfs(x-1, y)
        dfs(x+1, y)
        dfs(x, y-1)
        dfs(x, y+1)
        return True
    return False

result = 0
for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            result += 1

print(result)








n, m = map(int, input().split())

graph = []
for i in range(n):
    graph.append(list(map(int, input())))

def dfs(x, y):
    if x <= -1 or x>=n or y<= -1 or y>=m:
        return False
    if graph[x][y] == 0: # not visited yet
        graph[x][y] = 1
        dfs(x-1, y)
        dfs(x, y-1)
        dfs(x+1, y)
        dfs(x, y+1)
        return True
    return False

result = 0
for i in range(n):
    for j in range(m):
        # dfs process in present position
        if dfs(i, j) == True:
            result += 1

print(result)


'''
상세 분석
조건 설명
(x,y)
(x,y)에서 시작하여 DFS 탐색을 수행한다고 가정.
(x,y)의 값이 0이고, 상하좌우에 
(x,y+1)처럼 값이 0인 칸이 연결되어 있다면:
dfs(x, y)는 
(x,y+1)을 탐색하기 위해 dfs(x, y+1)을 호출합니다.
동작 흐름
if graph[x][y] == 0:
    graph[x][y] = 1  # 현재 노드를 방문 처리
    dfs(x-1, y)      # 상
    dfs(x+1, y)      # 하
    dfs(x, y-1)      # 좌
    dfs(x, y+1)      # 우
    return True      # 이 노드로 인해 새로운 덩어리를 발견했음을 반환
dfs(x,y)가 실행되면:
현재 노드 
(x,y)를 방문 처리 (graph[x][y] = 1).
연결된 모든 방향으로 탐색 (dfs(x-1, y), dfs(x+1, y), dfs(x, y-1), dfs(x, y+1)).
재귀적으로 연결된 모든 0이 탐색되지만, 최종적으로 
dfs(x,y)는 한 번만 True를 반환합니다.
True 반환의 의미
dfs(x,y+1)이 탐색을 수행하더라도:
dfs(x,y+1) 내부에서 True를 반환하는 경우는 없습니다. 이는 단순히 연결된 0을 처리하기 위한 재귀 호출일 뿐입니다.
dfs(x,y+1)의 반환값은 상위 호출에서 활용되지 않습니다.
최종적으로 
dfs(x,y)에서만 True가 반환되며, 이 True는 "새로운 덩어리 발견"을 나타냅니다.
예제 시나리오
그래프 예시
graph = [
    [0, 0, 1],
    [0, 1, 1],
    [1, 0, 0]]
dfs(0,0) 호출:
(0,0)에서 시작.
dfs(0,1)을 호출(우측 탐색).
dfs(0,1)에서 방문 처리 후 종료.
dfs(1,0)을 호출(하측 탐색).
dfs(1,0)에서 방문 처리 후 종료.
dfs(0,0)의 반환:
모든 연결된 0을 탐색 완료 → True 반환.
최종 결과
dfs(0,0)은 한 덩어리를 모두 탐색하고 True를 반환.
dfs(0,1)이나 
dfs(1,0)은 단순히 재귀 호출로서 처리되며, 최종적으로 True를 반환하지는 않습니다.
결론
dfs(x, y+1)의 반환값은 중요하지 않다: dfs(x, y+1)은 내부적으로 연결된 0을 탐색하기 위한 과정일 뿐, 상위 호출 
dfs(x,y)의 반환값에는 영향을 주지 않습니다.
결과적으로 새로운 True는 한 번만 반환: 
dfs(x,y) 함수는 새로운 연결된 덩어리를 탐색했을 때만 True를 반환합니다. 
dfs(x,y+1) 등 하위 호출은 단순히 탐색을 돕는 역할을 할 뿐입니다.
'''