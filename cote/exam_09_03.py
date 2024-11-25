# Floyd-Warshall 
'''
모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우 사용
- 다익스트라 알고리즘의 경우 단계마다 최단 거리를 가지는 노드를 하나씩 반복적으로 선택
- 그리고 해당 노드를 거쳐 가는 경로를 확인하며, 최단 거리 테이블을 갱신하는 방식
- 플로이드 워셜 역시 모든 노드가 아닌 거쳐가는 노드를 기준으로 알고리즘 수행
- 플로이드 워셜은 2차원 리스트에 최단 거리를 저장하는 특징이 있다.
- 다익스트라 알고리즘은 greedy 알고리즘, 플로이드 워셜은 다이나믹 프로그래밍 사용
- ex) 1번 노드에 대해 확인할 때 1번 노드를 중간에 거쳐 지나가는 모든 경우를 고려하면 됨.
- 현재 확인하고 있는 노드를 제외하고 N-1개의 노드 중에서 서로 다른 노드 (A, B)쌍을 선택하고
- A -> 1번노드 -> B의 비용을 확인한다음 최단 거리를 갱신
- 점화식  D_ab = min(D_ab, D_ak + D_kb)
'''

INF = int(1e9)

n = int(input())
m = int(input())

graph = [[INF]*(n+1) for _ in range(n+1)]

for a in range(n+1):
    for b in range(n+1):
        if a==b:
            graph[a][b] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = c

for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(1, n+1):
    for b in range(1, n+1):
        if graph[a][b] == INF:
            print("Infinity", end=" ")
        else:
            print(graph[a][b], end=" ")
    print()

print()