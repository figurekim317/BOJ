import sys
input = sys.stdin.readline

for i in range(int(input())):
    x, y, a, p, q, b = map(int, input().split())
    d=(x-p)**2+(y-q)**2
    r=(a+b)**2
    s=r-4*a*b
    if d==0 and a==b:
        print(-1)
    elif d==s or d==r:
        print(1)
    elif d>r or d<s:
        print(0)
    else:
        print(2)
