# quick sort
# pivot 설정하고 왼쪽부터 피벗보다 큰 데이터를 찾고, 오른쪽부터 피벗보다 작은 데이터를 찾는다.
# 그 다음 큰 데이터와 작은 데이터의 위치를 서로 교환해준다.
# 탐색이 중복되면 작은 데이터와 피벗의 위치를 서로 변경한다.
# 분할이 끝나면 피벗보다 작은 수는 왼쪽 피벗보다 큰 수는 오른쪽에 위치하게 된다.
# 왼쪽과 오른쪽 리스트도 퀵정렬을 실행한다. -- > 재귀함수
# 퀵 정렬은 리스트의 원소가 1개이면 종료된다.


array = [*map(int, input().split())]

def quick_sort(array):
    if len(array) <= 1:
        return array
    
    pivot = array[0]
    tail = array[1:]

    left_side = [x for x in tail if x<=pivot]
    right_side = [x for x in tail if x>pivot]

    return quick_sort(array(left_side)) + [pivot] + quick_sort(array(right_side))

print(quick_sort(array))