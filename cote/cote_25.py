def solution(N, stages):
    answer = []
    result = []
    count = [0] * (N + 2)
    
    # 각 스테이지에 멈춰 있는 사용자 수 계산
    for i in stages:
        count[i] += 1
    
    # 실패율 계산
    for i in range(1, N + 1): # 예외처리 놓침
        if sum(count[i:]) == 0:  # 진행 중인 사용자가 없으면 실패율 0
            failure_rate = 0
        else:
            failure_rate = count[i] / sum(count[i:])
        result.append((i, failure_rate))
    
    # 실패율 기준 내림차순 정렬 (실패율 동일 시 스테이지 번호 오름차순)
    result = sorted(result, key=lambda x: (-x[1], x[0])) # 낮은 숫자를 먼저 나오는 조건 빼먹음

    # 스테이지 번호만 추출
    for i in range(len(result)):
        answer.append(result[i][0])
    
    return answer

# sol
def solution(N, stages):
    answer = []
    length = len(stages)

    for i in range(1, N+1):
        count = stages.count(i)

        if length == 0:
            fail = 0
        else:
            fail = count / length
        
        answer.append((i, fail))
        length -= count

    answer = sorted(answer, key = lambda x:x[1], reverse = True)

    answer  = [i[0] for i in answer]
    return answer