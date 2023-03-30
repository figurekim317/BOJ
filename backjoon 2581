import sys
input = sys.stdin.readline

start = int(input())
last = int(input())

primes = []
for num in range(start, last+1):
    err = 0
    if num > 1 :
        for i in range(2, num):
            if num % i == 0:
                err += 1
                break
        if err == 0:
            primes.append(num)
            
if len(primes) > 0 :
    print(sum(primes))
    print(min(primes))
else:
    print(-1)
