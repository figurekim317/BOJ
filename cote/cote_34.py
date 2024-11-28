n = int(input())

data = [*map(int, input().split())]

dp = []
for i in range(n-1):
    if data[i] > max(data[i+1:]):
        dp.append(data[i])

print(dp)