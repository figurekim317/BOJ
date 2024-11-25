n = int(input())
data = [*map(int, input().split())]
data.sort()

def binary_search(array, target, start, end):
    while start <= end:
        mid = (start+end)//2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid-1
        else:
            start = mid+1
    return None

m = int(input())
x = [*map(int, input().split())]

for i in x:
    result = binary_search(data, i, 0, n-1)
    if result != None:
        print('yes', end=' ')
    else:
        print('no', end = ' ')