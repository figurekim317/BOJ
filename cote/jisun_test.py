# n을 입력받으면 n*n 행렬이 생성이 되는데 수를 적어서 넣는 과정이 n-소용돌이 방식으로 채운다. 그런다음 대각합의 결과를 return하라

def generate_spiral_matrix(n):
    matrix = [[0] * n for _ in range(n)]
    num = 1
    top, left = 0, 0
    bottom, right = n - 1, n - 1

    while num <= n * n:
        # Fill the top row
        for i in range(left, right + 1):
            matrix[top][i] = num
            num += 1
        top += 1

        # Fill the right column
        for i in range(top, bottom + 1):
            matrix[i][right] = num
            num += 1
        right -= 1

        # Fill the bottom row
        for i in range(right, left - 1, -1):
            matrix[bottom][i] = num
            num += 1
        bottom -= 1

        # Fill the left column
        for i in range(bottom, top - 1, -1):
            matrix[i][left] = num
            num += 1
        left += 1

    return matrix


def spiral_diagonal_sum(n):
    spiral_matrix = generate_spiral_matrix(n)
    main_diagonal_sum = sum(spiral_matrix[i][i] for i in range(n))
    return main_diagonal_sum

n = int(input())
print(generate_spiral_matrix(n))
print(spiral_diagonal_sum(n))
