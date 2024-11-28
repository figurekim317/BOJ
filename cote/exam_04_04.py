n, m = map(int, input().split())
# 방문한 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
d = [[0]*m for _ in range(n)]
# 현재 캐릭터의 x, y, 방향을 입력 받기
x, y, direction = map(int, input().split())
map_data = [[*map(int, input().split)] for _ in range(n)]
steps = [(-1, 0), (0, 1), (1, 0), (0, -1)]
d[x][y] = 1

def turn_left():
    direction -= 1
    if direction == -1:
        direction = 기

count = 1
turn_time = 0
while True:
    turn_left()
    nx = x + steps[direction]
    ny = y + steps[direction]

    if d[nx][ny] == 0 and map_data[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        count += 1
        turn_time = 0
        continue
    else:
        turn_time += 1

    if turn_time == 4:
        nx = x - steps[direction]
        ny = y - steps[direction]

        if map_data[nx][ny] == 0:
            x = nx
            y = ny
        else:
            break
        turn_time = 0

print(count)




'''1. 왼쪽 반시계 방향으로 회전한다. 
2. 회전한 후에 정면의 수가 0이라면 이동한다
4. count 1을 증가시킨다.
3. 원래 있던 자리를 1로 바꾼다.
4. 한 바퀴(4번 회전) 회전하고 나서 모든 방향의 값이 1이라면 거기에서 멈춘다. break
5. 카운트를 출력한다.
'''