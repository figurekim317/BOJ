n = int(input())
arr = []
for _ in range(n):
    input_data = input().split()
    arr.append((input_data[0], int(input_data[1]), int(input_data[2]), int(input_data[3])))

arr.sort(key=lambda x: (-x[1], x[2], -x[3], x[0]))

# 출력
for student in arr:
    print(student[0])
               