import sys

input = sys.stdin.readline
test_case = int(input())

for _ in range(test_case):
    n, m = map(int, input().split())
    temp = [*map(int, input().split())]
    array=[]
    for i in range(n):
        array.append(temp[i*m:(i+1)*m]) # temp[i*m : (i+1)*m] 이렇게도 표현 가능
    dp = [[0]*m for _ in range(n)]

    for i in range(n):
        dp[i][0] = array[i][0]

    for j in range(1, m):
        for i in range(n):
            left_up = dp[i - 1][j - 1] if i > 0 else 0
            left_down = dp[i + 1][j - 1] if i < n - 1 else 0
            left = dp[i][j - 1]

            dp[i][j] = array[i][j] + max(left_up, left_down, left)
    result = 0
    for i in range(n):
        result = max(result, dp[i][m-1])
    print(result)

'''
result = 0
for i in range(n):
    result = max(result, dp[i])
'''


'''
    a_n = a_(n-1) + max(an)
    0번그룹, 1번 그룹, ..., (n-1번 그룹)
 그룹에는 m개씩 들어감
0에서 (m-1)까지 진행시키면 됨


1번그룹에서 선택했으면 --> 0,1,2번 그룹에서 선택할 수 있음 
각 자 자리에서 최대값을 설정해서 dp table 채우고 마지막 열을 확인하면 됨.. (아이디어 놓침)
'''