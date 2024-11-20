def rotate_a_matrix_by_90_degree(a):
    ''' 입력: nxn 행렬 
        반환: 회전된 행렬
    '''
    n = len(a)  # 행의 길이 계산
    m = len(a[0])  # 열의 길이 계산
    result = [[0]*n for _ in range(m)]  # 결과를 담을 리스트 초기화
    for i in range(n):
        for j in range(m):
            result[j][n-i-1] = a[i][j]  # 행렬을 90도 회전하여 결과에 저장
    return result

def check(new_lock):
    lock_length = len(new_lock)//3  # 원래 자물쇠의 크기 계산
    for i in range(lock_length, lock_length*2):
        for j in range(lock_length, lock_length*2):
            if new_lock[i][j] != 1:  # 중간 부분이 모두 1인지 확인
                return False
    return True

def solution(key, lock):
    n = len(lock)  # 자물쇠의 크기
    m = len(key)   # 열쇠의 크기
    # 자물쇠의 크기를 3배로 확장한 새로운 자물쇠 생성
    new_lock = [[0]*(n*3) for _ in range(n*3)]
    
    # 새로운 자물쇠의 중앙 부분에 기존 자물쇠 값 복사
    for i in range(n):
        for j in range(n):
            new_lock[i+n][j+n] = lock[i][j]
                
    # 열쇠를 4번 회전하며 모든 경우 탐색
    for rotation in range(4):
        key = rotate_a_matrix_by_90_degree(key)  # 열쇠를 90도 회전
        for x in range(n*2):
            for y in range(n*2):
                # 열쇠의 각 위치에 대해 자물쇠에 더하기
                for i in range(m):
                    for j in range(m):
                        new_lock[x+i][y+j] += key[i][j]
                # 새로운 자물쇠가 올바른지 확인
                if check(new_lock):
                    return True
                # 열쇠를 뺌으로써 자물쇠 원상복구
                for i in range(m):
                    for j in range(m):
                        new_lock[x+i][y+j] -= key[i][j]
    return False
