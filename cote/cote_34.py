n = int(input())

data = [*map(int, input().split())]

dp = []
for i in range(n-1):
    if data[i] > max(data[i+1:]):
        dp.append(data[i])

print(len(data)-len(dp)-1)


n = int(input())
data = list(map(int, input().split()))

# DP 테이블 초기화 (모든 병사의 LDS 길이를 1로 초기화)
dp = [1] * n

# 모든 병사에 대해 감소하는 부분 수열 계산
for i in range(1, n):
    for j in range(0, i):
        if data[j] > data[i]:  # 내림차순 조건
            dp[i] = max(dp[i], dp[j] + 1)

# 가장 긴 감소하는 부분 수열의 길이
longest_decreasing = max(dp)

# 열외해야 하는 병사의 수
result = n - longest_decreasing
print(result)
