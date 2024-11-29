n = int(input())
arr = [*map(int, input().split())]
arr.sort()

def cal_min(arr, candidate):
    result = 0
    for i in range(len(arr)):
        result += abs(arr[i] - arr[candidate])  # candidate를 인덱스로 사용
    return result, candidate

min_value = float('inf')  # 더 큰 초기값으로 설정
final = 0  # 최소값을 가지는 인덱스를 저장

# 모든 인덱스에 대해 차이 합 계산
for i in range(len(arr)):
    temp, pos = cal_min(arr, i)
    if min_value > temp:
        min_value = temp
        final = pos  # 최소값을 가지는 인덱스 업데이트

print(final)

# sol
print(arr[(n-1//2)])
