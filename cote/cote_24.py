n = int(input())
arr = [*map(int, input().split())]
arr.sort()
candidate = 0

def cal_min(arr, candidate):
    result = 0
    for i in range(len(arr)):
        result += abs(arr[i]-arr[candidate])
    return result, candidate

min_value = 999999999

for i in range(len(arr)):
    temp, pos = cal_min(arr, candidate+i)
    if min_value > temp:
        min_value = temp
        final = pos

print(final)