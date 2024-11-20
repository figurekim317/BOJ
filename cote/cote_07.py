N = input()
result = 0
length = len(N)

for i in range(length):
    result += int(N[i])

for i in range(length//2, length):
    result -= int(N[i])

if result!=0:
    print("READY")
else:
    print("LUCKY")

# BOJ solution
n = list(input())
n = list(map(int, n))

if sum(n[:len(n)//2]) == sum(n[len(n)//2:]):
    print("LUCKY")
else:
    print("READY")


import sys
input = sys.stdin.readline

s = input().rstrip()

a = s[:len(s)//2]
b = s[len(s)//2:]

if sum(list(map(int, a))) == sum(list(map(int, b))):
    print("LUCKY")
else:
    print("READY")