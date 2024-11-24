# insert sorting

data = [*map(int, input().split())]

for i in range(len(data)):
    for j in range(i, 0 , -1):
        if data[j] < data[j-1]:
            data[j], data[j-1] = data[j-1], data[j]
        else:
            break

