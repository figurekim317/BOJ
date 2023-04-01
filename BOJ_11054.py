# 가장 긴 바이토닉 부분 수열
import sys
input = sys.stdin.readline

n = int(input())
case = [*map(int, input().split())]
inc = [1 for i in range(n)]
dec = [1 for i in range(n)]
res = [0 for i in range(n)]

for i in range(n):
    for j in range(i):
        if case[i] > case[j]:
            inc[i] = max(inc[i], inc[j]+1)

for i in range(n-1, -1, -1):
    for j in range(n-1, i, -1):
        if case[i] > case[j]:
            dec[i] = max(dec[i], dec[j]+1)

for i in range(n):
    res[i] = inc[i] + dec[i]-1
print(max(res))
