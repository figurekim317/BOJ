import sys
input = sys.stdin.readline

def fib(N):
    zeros=[1,0,1]
    ones=[0,1,1]
    if N >= 3:
        for i in range(2,N):
            zeros.append(zeros[i-1] + zeros[i])
            ones.append(ones[i-1] + ones[i])
    print(f"{zeros[N]} {ones[N]}")
 
T = int(input())
for _ in range(T):
    N = int(input())
    fib(N)

#short coding

T = int(input())
for _ in range(T):
    N = int(input())
    zero,one=1,0 # zero: 0개수, one: 1개수
    for i in range(N):
        zero,one = one,zero+one # zero와 one에 대해 피보나치적용
    print(zero,one)
