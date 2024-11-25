# count sort
# 전체 list를 탐색하며 수가 발견될 때 전체 개수를 1개씩 증가시킴

array = [*map(int, input().split())]
count_arr = [0]*(max(array)+1)

for i in range(len(array)):
    count_arr[array[i]] += 1

for i in range(len(count_arr)):
    for j in range(count_arr[i]):
        print(i, end=' ')


# python 내장 기본 정렬 라이브러리인 sorted()는 퀵정렬과 동작방식이 비슷한 병합정렬을 기반으로 만들어짐
# 병합정렬은 일반적으로 퀵정렬보다는 느리지만 최악의 경우에도 O(NlogN)을 보장함

arr = [('바나나', 2), ('사과', 5), ('당근', 3)]

result = sorted(arr, key = lambda x:x[1])
print(result)