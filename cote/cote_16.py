n, m = map(int, input().split())
data = []
temp = [[0]*m for _ in range(n)]

for _ in range(n):
    data.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

result = 0

def virus(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx >=0 and nx<n and ny>=0 and ny<m:
            if temp[nx][ny] == 0:
                temp[nx][ny] = 2
                virus(nx, ny)


def get_score():
    score = 0
    for i in range(n):
        for j in range(m):
            if temp[i][j] == 0:
                score += 1
    return score

def dfs(count):
    global result
    if count == 3:
        for i in range(n):
            for j in range(m):
                temp[i][j] = data[i][j]

        for i in range(n):
            for j in range(m):
                if temp[i][j] == 2:
                    virus(i, j)

        result = max(result, get_score())
        return
    for i in range(n):
        for j in range(m):
            if data[i][j] == 0:
                data[i][j] = 1
                count += 1
                dfs(count)
                data[i][j] = 0
                count -= 1

dfs(0)
print(result)


# chatgpt가 해준 최적화

from itertools import combinations
from collections import deque
import copy

n, m = map(int, input().split())
data = []
for _ in range(n):
    data.append(list(map(int, input().split())))

# 방향벡터
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 바이러스 확산 (BFS 사용)
def spread_virus(temp, virus_positions):
    queue = deque(virus_positions)
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and temp[nx][ny] == 0:
                temp[nx][ny] = 2
                queue.append((nx, ny))

# 안전 영역 계산
def get_safe_area(temp):
    return sum(row.count(0) for row in temp)

# 벽을 세울 수 있는 위치와 초기 바이러스 위치를 저장
empty_spaces = [(i, j) for i in range(n) for j in range(m) if data[i][j] == 0]
virus_positions = [(i, j) for i in range(n) for j in range(m) if data[i][j] == 2]

result = 0

# 벽을 세울 수 있는 모든 경우의 수 탐색
for walls in combinations(empty_spaces, 3):
    # 맵 복사
    temp = copy.deepcopy(data)

    # 벽 설치
    for x, y in walls:
        temp[x][y] = 1

    # 바이러스 확산
    spread_virus(temp, virus_positions)

    # 안전 영역 계산
    result = max(result, get_safe_area(temp))

print(result)

'''
주요 변경 사항
조합 사용:
itertools.combinations를 사용하여 벽을 설치할 3개의 위치를 사전에 계산.
총 벽 설치 경우의 수는 C(k,3) 여기서 k는 0의 개수입니다.
바이러스 전파를 BFS로 변경:
스택 오버플로우 방지를 위해 deque를 사용한 BFS로 구현.
미리 빈 공간과 바이러스 위치 계산:
반복적인 탐색 대신 초기 데이터에서 벽 설치 가능한 위치와 바이러스 위치를 미리 리스트로 저장.
맵 복사를 copy.deepcopy로 처리:
원본 맵을 훼손하지 않으면서 안전 영역 계산.
'''