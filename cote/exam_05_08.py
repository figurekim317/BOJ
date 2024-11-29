from collections import deque

graph = [[], [2, 3, 8], [1, 7], [1, 4, 5], [3, 5], [3, 4], [7], [2, 6, 8], [1, 7]]
visited = [False] * 9

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

dfs(graph, 1, visited)
bfs(graph, 1, visited)

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)
        
def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for i in graph[v]:
            if not visited[v]:
                queue.append(i)
                visited[i] = True


'''재귀 함수로 DFS를 구현하면 컴퓨터 시스템의 특성상 실제 프로그램의 수행 시간은 느려질 수 있다.
따라서 스택 라이브러리를 이용해 시간 복잡도를 완화하는 테크닉이 필요할 때도 있다. 이 내용은 책의 범위를 벗어나므로
코딩 테스트에서는 보통 DFS보다는 BFS 구현이 조금 더 빠르게 동작한다는 정도로 기억하자.

재귀 DFS의 수행 시간과 스택 기반 DFS의 차이
재귀적으로 DFS(Depth-First Search)를 구현할 때와 스택을 이용한 반복적 DFS 구현의 성능 차이는 다음과 같은 이유에서 발생합니다:
1. 재귀 DFS의 문제점: 함수 호출 오버헤드
함수 호출 스택 사용: 재귀 DFS는 시스템의 함수 호출 스택을 사용합니다. 각 재귀 호출 시, 함수 호출 정보를 저장(스택 프레임 생성)하고, 반환 시 스택 프레임을 해제해야 합니다.
오버헤드: 이러한 과정은 스택 포인터 조작, 레지스터 백업 등으로 인해 시간이 추가로 소요됩니다.
스택 한계: 시스템의 호출 스택은 크기가 제한되어 있어, 깊은 재귀 호출(예: 수천에서 수만 번의 호출)이 발생하면 스택 오버플로우로 프로그램이 종료될 수 있습니다.
2. 스택 라이브러리를 활용한 반복적 DFS
명시적 스택 사용: 반복적 DFS는 명시적으로 스택 자료구조를 사용해 탐색 경로를 관리합니다. 이는 시스템 호출 스택 대신 애플리케이션이 메모리 상에서 관리하는 스택을 사용하므로 호출 스택 오버플로우 문제가 발생하지 않습니다.
더 적은 오버헤드: 함수 호출을 피하므로 호출 스택 관련 작업이 없어지고, 실행 시간이 줄어듭니다. 따라서 실제로 반복적 DFS가 수행 속도가 더 빠릅니다.
3. 시간 복잡도
DFS의 이론적 시간 복잡도는 재귀 DFS와 반복적 DFS 모두 동일하게 O(V+E)입니다. 여기서 V는 정점의 수, E는 간선의 수입니다.
그러나 실제 수행 시간은 함수 호출 오버헤드와 메모리 관리 효율성의 영향을 받아 반복적 DFS가 재귀 DFS보다 빠르게 동작할 수 있습니다.
BFS(너비 우선 탐색)의 구현 속도가 빠른 이유
BFS는 일반적으로 큐(queue)를 사용하여 구현됩니다.
DFS(특히 재귀 DFS)와 비교했을 때, BFS의 큐 기반 구현은 함수 호출 스택을 사용하지 않고, 반복문만으로 탐색을 처리하므로 추가적인 호출 오버헤드가 없습니다.
BFS는 DFS와는 다른 탐색 전략을 사용하며, 코딩 테스트에서는 그래프 탐색이 필요할 때 BFS로 조건을 만족하는 노드(최단 경로, 특정 조건)를 빨리 찾을 수 있어 실질적으로 더 유리한 경우가 많습니다.
코딩 테스트에서의 요약:
DFS보다 BFS가 더 빠를 가능성이 높은 이유:
BFS는 반복문과 큐를 사용해 오버헤드가 적음.
최단 경로 등 특정 조건을 만족하는 경로를 탐색할 때, BFS는 경로를 짧은 순서대로 탐색하여 더 효율적.
재귀 DFS의 한계:
함수 호출 스택의 깊이에 제한이 있어, 깊은 탐색이 필요한 경우 문제가 발생.
함수 호출에 따른 추가적인 수행 시간 증가.
스택 기반 DFS:
함수 호출을 제거해 재귀 DFS의 오버헤드를 해결.
BFS에 비해 깊이 우선 탐색이 필요한 경우 적합.
결론적으로, 코딩 테스트에서는 BFS가 DFS보다 구현 속도가 빠른 경우가 많으므로, BFS로 해결할 수 있는 문제라면 이를 우선적으로 고려하는 것이 좋습니다.

'''