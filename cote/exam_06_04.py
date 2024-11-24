# count sort
# 전체 list를 탐색하며 수가 발견될 때 전체 개수를 1개씩 증가시킴

array = [*map(int, input().split())]
count_arr = [0]*(max(array)+1)

for i in range(len(array)):
    count_arr[array[i]] += 1

for i in range(len(count_arr)):
    for j in range(count_arr[i]):
        print(i, end=' ')

        