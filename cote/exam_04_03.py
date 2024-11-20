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