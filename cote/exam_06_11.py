n = int(input())
arr = []

for _ in range(n):
    input_data = input().split()
    arr.append((input_data[0], int(input_data[1])))

arr = sorted(arr, key=lambda x: x[1])

for i in range(n):
    print(arr[i][0], end=' ')