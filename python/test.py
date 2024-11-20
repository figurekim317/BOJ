import sys

input = sys.stdin.readline().rstrip()

n, m, l = map(int, input().split())

answer = 7

print(f"정답은 {answer}입니다.")

standard library
itertools
- 순열과 조합 라이브러리
- combinations(data, 2) : 가능한 조합의 수를 구해줌
- combinations_with_replacement: 중복해서 조합의 수를 구해줌 (본인 포함)

heapq
- 힙 기능을 제공하는 라이브러리
- 다익스트라 최단 경로 알고리즘을 포함해 다양한 알고리즘에서 우선순위 큐 기능을 구현
- heapq.heappush() : 원소 삽입
- heapq.heappop() : 원소 꺼낼 때
- 파이썬에서 내장된 것은 minheapq를 제공함

import heapq

def heapsort(iterable):
    h = []
    result = []

    for value in iterable:
        heapq.heappush(h, value)
    for i in range(len(h)):
        result.append(heapq.heappop(h))
    return result



bisect
- 이진 탐색을 제공하는 라이브러리
- 파이썬에서 이진 탐색을 쉽게 구현할 수 있도록 bisect 라이브러리 제공
- 정렬된 배열에서 특정한 원소를 찾을 때 유용
from bisect import bisect_left, bisect_right
a = [1, 2, 4, 4, 8]
x = 4

def count_by_range(a, bisect_left, bisect_right):
    right_idx = bisect_right(a, right_value)
    left_idx = bisect_left(a, left_value)
    return right_idx - left_idx
print(bisect_left(a, x))
print(bisect_right(a, x))



collections
- 덱, 카운터 등의 유용한 자료구조
deque
- 리스트 자료형의 경우 데이터 삽입, 삭제 등의 다양한 기능을 제공한다.
- 리스트의 경우 중간의 특정 원소 삽입도 가능. 하지만 append를 사용하거나 pop을 사용하는 경우 가장 마지막 원소를 기준으로 수행
- 앞쪽에 있는 원소를 처리할 때 데이터의 갯수에 따라 많은 시간이 소요될 수 있음
- deque의 경우 인덱싱, 슬라이싱 등의 기능은 사용할 수 없다.
- 연속적으로 나열된 데이터의 시작 부분이나 끝부분에 데이터를 삽입하거나 삭제할 때는 매우 효과적으로 사용 가능
- deque는 popleft를 사용하면 가장 처음 원소를 제거 할 수 있음
- pop은 가장 마지막 원소를 제거할 때 사용
- appendleft(x)를 하면 가장 왼쪽에, append는 마지막 인덱스에 원소를 삽입

counter = Counter(리스트)
- 리스트 내부에 특정 원소가 등장한 횟수를 출력

math
- 필수적인 수학적기능 포함
- max, min, sum
- eval("(3+5)*7") 과 같이 문자열 형태로 주어진 수식을 계산
- sorted(): iterable 객체가 들어왔을 때, 정렬된 결과를 반환, key의 형태로 정리도 가능
result = sorted([('홍길동', 35), ('이순신', 30)], key = lambda x:x[1], reverse=True)

- gcd : 최대공약수
- 


n = 1260
count = 0

coin_types = [500, 100, 50, 10]

for coin in coin_types:
    count += n//coin
    n %= coin

print(count)

n, m, k = map(int, input().split())
data = list(map(int, input().split()))
data.sorted(reverse=True)
result = 0

if n%(k+1) == 0:
    result = (data[0]*k+data[1])*(n//(k+1))
else:
    result = (data[0]*k+data[1])*(n//(k+1)) + data[0]*(n%(k+1)
                                                       