377
n = int(input())
data = [[*map(int, input().split())] for _ in range(n)]

dp = []
left = data[i-1][0] + dp[i-1][0]
right = data[i-1][-1] + dp[i-1][-1]
dp[i][j] = dp[i-1][j] + max(data[i-1][j-1], data[i-1][j])

n = int(input())
data = [[*map(int, input().split())] for _ in range(n)]

# DP 테이블 초기화
dp = [[0] * (i + 1) for i in range(n)]
dp[0][0] = data[0][0]  # 삼각형의 꼭대기 값으로 초기화

# DP 테이블 채우기
for i in range(1, n):
    for j in range(i + 1):
        if j == 0:  # 맨 왼쪽 경계
            dp[i][j] = dp[i - 1][j] + data[i][j]
        elif j == i:  # 맨 오른쪽 경계
            dp[i][j] = dp[i - 1][j - 1] + data[i][j]
        else:  # 중간 부분
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + data[i][j]

# 결과 출력: 마지막 행의 최댓값
print(max(dp[-1]))

# 최적화 코드

n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

# 이전 결과를 저장하는 배열
dp = data[0]  # 첫 번째 행으로 초기화

# DP 갱신
for i in range(1, n):
    new_dp = [0] * (i + 1)  # 현재 행에 대한 새로운 DP 값 계산
    for j in range(i + 1):
        if j == 0:  # 맨 왼쪽 경계
            new_dp[j] = dp[j] + data[i][j]
        elif j == i:  # 맨 오른쪽 경계
            new_dp[j] = dp[j - 1] + data[i][j]
        else:  # 중간 부분
            new_dp[j] = max(dp[j - 1], dp[j]) + data[i][j]
    dp = new_dp  # 갱신된 DP로 업데이트

# 결과 출력: 마지막 행의 최댓값
print(max(dp))
