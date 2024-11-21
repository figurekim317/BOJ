import sys
input = sys.stdin.readline

def dfs(value, idx, add, sub, mul, div):
    if idx == N:
        answer.append(value)
        return
    
    if add:
        dfs(value+A[idx], idx+1, add-1, sub, mul, div)
    if sub:
        dfs(value+A[idx], idx+1, add, sub-1, mul, div)
    if mul:
        dfs(value+A[idx], idx+1, add, sub, mul-1, div)
    if div:
        dfs(value+A[idx], idx+1, add, sub, mul, div-1)
    
N = int(input())
A = [*map(int, input().split())]
add, sub, mul, div = map(int, input().split())

answer = []
dfs(A[0], 1, add, sub, mul, div)
print(max(answer))
print(min(answer))
       