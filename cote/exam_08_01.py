# 재귀함수를 이용하는 방법(memoization)에서는 한 번 푼 문제를 그 결과를 저장해 놓았다가 
# 나중에 동일한 문제를 풀어야 할 때 이미 저장한 값을 반환한다.
# 재귀함수를 사용하면 컴퓨터 시스템에서는 함수를 다시 호출했을 때 메모리 상에 적재되는 일련의 과정을 따라야 하므로
# 오버헤드가 발생할 수 있다.
# 따라서 재귀함수 대신에 반복문을 사용하여 오버헤드를 줄일 수 있다.
# memoization = 하향식
# bottom up = 상향식

d = [0] * 100

def fibo(x):
    if x == 1 or x ==2:
        return 1
    if d[x] != 0:
        return d[x]
    d[x] = fibo(x-1) + fibo(x-2)
    return d[x]

print(fibo(99))


d[1] = 1
d[2] = 1
n = 99

for i in range(3, n+1):
    d[i] = d[i-1] + d[i-2]

print(d[n])
