# 못품
import heapq

def solution(food_times, k):
    # 모든 음식을 다 먹을 수 있는 경우
    if sum(food_times) <= k:
        return -1
    
    # (음식 시간, 인덱스) 형태로 힙에 넣기
    q = []
    for i in range(len(food_times)):
        # (음식시간, 음식번호) 형태로 우선순위 큐에 삽입
        heapq.heappush(q, (food_times[i], i + 1))
    
    sum_value = 0 # 먹기 위해 사용한 시간
    previous = 0 # 직전에 다 먹은 음식 시간
    length = len(food_times) # 남은 음식의 개수

    # sum_value + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
    while sum_value + (q[0][0] - previous*length) <= k:
        now = heapq.heappop(q)[0]
        sum_value += (now - previous)*length
        length -= 1
        previous = now
    
    result = sorted(q, key = lambda x:x[1])
    return result[(k-sum_value)%length][1]

