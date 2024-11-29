current_position = input()
row = int(ord(current_position[0]))-int(ord('a')) + 1
col = int(current_position[1])

steps = [(1, 2), (-1, 2), (1, -2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]

result = 0

for step in steps:
    nrow = row + step[0]
    ncol = col + step[1]
    if nrow < 1 or nrow >8 or ncol < 1 or ncol > 8:
        continue
    result += 1

print(result)

input_data = input()
row = int(input_data[1])
col = int(ord(input_data[0]))- int(ord('a')) + 1

steps = [(-2, -1), (-2, 1), (2, 1), (2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

result = 0
for step in steps:
    next_row = row + step[0]
    next_col = col + step[1]

    if 1<= next_row <=8 and 1<= next_col <= 8:
        result += 1

print(result)
