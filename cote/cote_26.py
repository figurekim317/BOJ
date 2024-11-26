364
554
# 못품
import heapq

n = int(input())  # 카드 묶음의 개수

heap = []
for i in range(n):
    data = int(input())
    heapq.heappush(heap, data)  # 최소 힙에 데이터 추가

result = 0

# 힙에서 두 개씩 꺼내어 최소 비교 횟수 계산
while len(heap) != 1:
    one = heapq.heappop(heap)  # 가장 작은 카드 묶음
    two = heapq.heappop(heap)  # 두 번째로 작은 카드 묶음

    sum_value = one + two  # 두 묶음을 합침
    result += sum_value    # 비교 횟수에 추가
    heapq.heappush(heap, sum_value)  # 새로운 묶음을 다시 힙에 추가

print(result)  # 최소 비교 횟수 출력
