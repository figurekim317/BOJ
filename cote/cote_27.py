n, target = map(int, input().split())
data = [*map(int, input().split())]
result = [0]*(10000001)

for i in data:
    result[i] += 1

if result[target] != 0:
    print(result[target])
else:
    print(-1)

# sol 1
def count_by_value(array, x):
    # 데이터의 수
    n = len(array)

    # x가 처음 등장한 인덱스 계산
    a = first(array, x, 0, n-1)

    # 수열에 x가 존재하지 않는 경우
    if a == None:
        return 0 # 값이 x인 원소의 개수는 0개이므로 0 변환
    
    # x가 마지막으로 등장한 인덱스 계산
    b = last(array, x, 0, n-1)

    return b-a+1

def first(array, target, start, end):
    if start>end:
        return None
    mid = (start+end)//2
    # 해당 값을 가지는 원소 중에서 가장 왼쪽에 있는 경우에만 인덱스 반화
    if (mid==0 or target > array[mid-1]) and array[mid] == target:
        return mid
    elif array[mid] >= target:
        return first(array, target, start, mid-1)
    else:
        return first(array, target, mid+1, end)
    
def last(array, target, start, end):
    if start > end:
        return None
    mid = (start+end)//2

    if(mid == n-1 or target < array[mid+1]) and array[mid] == target:
        return mid
    elif array[mid] > target:
        return last(array, target, start, mid-1)
    else:
        return last(array, target, mid+1, end)
    

n, x = map(int, input().split())
array = list(map(int, input().split()))

count = count_by_value(array, x)

if count == 0:
    print(-1)
else:
    print(count)

# sol 2
from bisect import bisect_left, bisect_right

def count_by_range(array, left_value, right_value):
    right_index = bisect_right(array, right_value)
    left_index = bisect_left(array, left_value)
    return right_index - left_value


n, x = map(int, input().split())
array = list(map(int, input().split()))

count = count_by_value(array, x)

if count == 0:
    print(-1)
else:
    print(count)
