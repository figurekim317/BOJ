def binary_search(array, start, end):
    if start > end:
        return None
    
    mid = (start + end)//2
    if array[mid] == mid:
        return mid
    elif array[mid] > mid:
        return binary_search(array, start, mid-1)
    else:
        return binary_search(array, mid+1, end)
    

# 입력 처리
n = int(input())
array = list(map(int, input().split()))

# 이진 탐색 수행
result = binary_search(array, 0, n - 1)

# 결과 출력
if result != None:
    print(result)
else:
    print(-1)
