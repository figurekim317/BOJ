n = int(input())
x, y = 1, 1
plans = input().split()

# 방향에 따른 이동 값을 딕셔너리로 정의
directions = {
    'L': (0, -1),
    'R': (0, 1),
    'U': (-1, 0),
    'D': (1, 0)
}

for plan in plans:
    if plan in directions:  # 유효한 이동 경로인지 확인
        dx, dy = directions[plan]
        nx = x + dx
        ny = y + dy
        # 이동이 가능한지 확인
        if 1 <= nx <= n and 1 <= ny <= n:
            x, y = nx, ny

print(x, y)
