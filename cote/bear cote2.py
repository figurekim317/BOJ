def GameChallenge(strArr):
    # __define-ocg__: Tic-Tac-Toe 보드 상태를 분석하여 승리 가능한 위치를 찾는 함수

    # 2차원 보드로 변환
    board = [
        strArr[:3],  # 첫 번째 행
        strArr[4:7],  # 두 번째 행
        strArr[8:]  # 세 번째 행
    ]

    # 조건 검사를 위한 변수
    varFiltersCg = []  # 승리 조건을 저장하는 리스트

    # 가로 승리 조건
    for r in range(3):
        if board[r].count("X") == 2 and board[r].count("-") == 1:
            varFiltersCg.append((r, board[r].index("-")))
        if board[r].count("O") == 2 and board[r].count("-") == 1:
            varFiltersCg.append((r, board[r].index("-")))

    # 세로 승리 조건
    for c in range(3):
        col = [board[r][c] for r in range(3)]  # 각 열의 값을 추출
        if col.count("X") == 2 and col.count("-") == 1:
            varFiltersCg.append((col.index("-"), c))
        if col.count("O") == 2 and col.count("-") == 1:
            varFiltersCg.append((col.index("-"), c))

    # 대각선 승리 조건
    diagonals = [
        [(0, 0), (1, 1), (2, 2)],  # 왼쪽 위에서 오른쪽 아래 대각선
        [(0, 2), (1, 1), (2, 0)]   # 오른쪽 위에서 왼쪽 아래 대각선
    ]
    for diag in diagonals:
        values = [board[r][c] for r, c in diag]  # 대각선 값 추출
        if values.count("X") == 2 and values.count("-") == 1:
            varFiltersCg.append(diag[values.index("-")])
        if values.count("O") == 2 and values.count("-") == 1:
            varFiltersCg.append(diag[values.index("-")])

    # 가능한 승리 위치
    varOcg = varFiltersCg[0] if varFiltersCg else None 

#    "Each board will only have one solution for a win, not multiple wins."
# (각 보드는 승리를 위한 유일한 위치만 가집니다. 중복으로 승리 위치가 나오는 경우는 없습니다.)

    # 결과를 인덱스 형식으로 변환
    if varOcg:
        row, col = varOcg
        result_index = row * 4 + col  # 1차원 배열 인덱스 변환
        return result_index
    return -1  # 승리 가능한 위치가 없는 경우

# 예제 실행
print(GameChallenge(["X", "-", "O", "<>", "-", "O", "-", "<>", "O", "X", "-"]))  # 결과: 5
print(GameChallenge(["X", "O", "X", "<>", "-", "O", "O", "<>", "X", "X", "O"]))  # 결과: 4
