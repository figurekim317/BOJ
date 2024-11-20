import sys

input = sys.stdin.readline

n, m = map(int, input().split())
data = list(map(int, input().split()))
data_sum = [0]*(n)
c = [0]*n
data_sum[0] = data[0]
answer = 0

for i in range(1, n):
    data_sum[i] = data_sum[i-1] + data[i]

for i in range(n):
    remainder = data_sum[i]%m
    if remainder == 0:
        answer += 1
    c[remainder] += 1

for i in range(m):
    if c[i] > 1:
        answer += (c[i] * (c[i]-1)//2)

print(answer)