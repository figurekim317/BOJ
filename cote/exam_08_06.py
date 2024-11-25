# 점화식: an = max(a_n-2+n, a_n-1)

n = int(input())
array = [*map(int, input().split())]

d = [0]*100

d[0] = array[0]
d[1] = max(array[0], array[1])

for i in range(2, n):
    d[i] = max(d[i-2]+array[i], d[i-1])

print(d[n-1])

