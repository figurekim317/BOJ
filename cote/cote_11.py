# 못풀었음. 복습 꼭 해야함!
n = int(input())
apple_n = int(input())
data = [[0]*(n+1) for _ in range(n+1)]
dir_info = []

# map information(if there is apple == 1)
for _ in range(apple_n):
    a, b = map(int, input().split())
    data[a][b] = 1

# direction information
dir_n = int(input())
for _ in range(dir_n):
    x, c = input().split()
    dir_info.append((int(x), c))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def turn(direction, c):
    if c == 'L':
        direction = (direction-1)%4
    if c == 'D':
        direction = (direction+1)%4
    return direction

def simulate():
    x, y = 1, 1
    data[x][y] = 2 # 뱀이 존재하는 위치는 2로 표시
    direction = 0 # 처음에는 동쪽
    time = 0 # 시작한 다음 지난 시간
    index = 0 # 다음에 회전할 정보
    q = [(x, y)] # 뱀이 차지하고 있는 위치 정보(꼬리가 앞쪽)

    while True:
        nx = x + dx[direction]
        ny = y + dy[direction]
        # 맵 범위 안에 있고 뱀의 몸통이 없는 위치라면
        if 1<= nx and nx <=n and 1<= ny and ny <= n and data[nx][ny] !=2:
            # 사과가 없다면 디동 후에 꼬리 제거
            if data[nx][ny] == 0:
                data[nx][ny] =2
                q.append((nx, ny))
                px, py = q.pop(0)
                data[px][py] = 0
            if data[nx][ny] == 1:
                data[nx][ny] = 2
                q.append((nx, ny))
        else:
            time += 1
            break
        x, y = nx, ny
        time += 1
        if index < len(dir_info) and time == dir_info[index][0]: # index 범위 지정하는 것 놓침
            direction = turn(direction, dir_info[index][1])
            index += 1
    return time

print(simulate())