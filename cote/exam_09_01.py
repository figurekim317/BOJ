# Dijkstra
'''
첫 노드 선택 -> 갈 수 있는 간선 확인하고 나머지는 int(1e9)로 유지
가장 가까운 노트 갱신하고 (이동 값+갈 수 있는 노드의 거리)를 기준으로 선택
다른 노드를 선택했을 때 기존 테이블의 값보다 작지 않으면 업데이트는 일어나지 않는다.
실제로 컴퓨터 안에서 처리할 때 이차원 배열의 형태로 처리한다. 특정 행에서 열로 가는 비

stack: 가장 나중에 삽입된 데이터 추출
queue: 가장 먼저 삽입된 데이터 추출
priority queue: 가장 우선순위가 높은 데이터(최소힙, 최대힙을 이용, 최소힙은 값이 낮은 데이터부터 삭제)
priority queue보다 heapq가 더 빠르게 동작함.
priority queue를 구현할 때는 heap을 이용하게 된다.
우선순위 큐는 배열, 연결리스트, 힙으로 구현이 가능하다.
heap은 완전 이진트리의 일종으로 우선순위 큐를 위해 만들어진 자료구조이다.

이진탐색트리
- 이진 탐색과 연결리스트(linked-list)를 결합한 자료구조의 일종이다.
- 이진 탐색의 효율적인 탐색 능력을 유지하면서 빈번한 자료의 입력과 삭제를 가능하도록 한다.
- 각 노드에서 왼쪽의 자식 노드는 해당 노드보다 작은 값으로, 오른쪽의 자식 노드는 해당 노드보다 큰 값으로 이루어져 있다.

차이점

- (최대힙의 경우) 힙은 각 노드의 값이 자식 노드보다 크거나 같다.
- 이진 탐색 트리는 각 노드의 왼쪽 자식은 더 작은 값으로, 오른쪽 자식은 더 큰 값으로 이루어져있다.
    - 왼쪽 자식 노드 < 부모 노드 < 오른쪽 자식 노드
- 힙은 왼쪽 노드의 값이 크든 오른쪽 노드의 값이 크든 상관 없다.
- 힙은 최대/최소 검색을, 이진 탐색 트리는 탐색을 위한 구조이다.

'''

import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())

start = int(input())
graph = [[] for i in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    # a: 해당 노드 # b번 노드까지 가는 비용이 c
    graph[a].append((b, c))


def dijkstra(start):
    q = []
    # q자체는 우선순위 큐로 생각하면 됨. 처음이라 시작노드까지의 거리는 0, 시작노드 나중에도 현재 노드가 됨
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        # 가장 최단 거리가 짧은 노드에 대한 정보를 꺼내기
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        for candidate in graph[now]:
            cost = dist + candidate[1]
            if cost < distance[candidate[0]]:
                distance[candidate[0]] = cost
                heapq.heappush(q, (cost, candidate[0]))

