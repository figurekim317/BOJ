n, m = map(int, input().split())
array = list(map(int, input().split()))
array.sort()
candidate = 0

'''
1. array 정렬
2. candidate를 설정
3. 모든 떡을 살펴보며 잘라본다. 만약에 길이보다 작다면 변화없음. 길이보다 길다면 뺀 값을 더해줌
4. 더해준 값이 원하는 값보다 크다면 그때 candidate 값을 설정
'''

temp = 0
while temp<m:
    for i in array:
        if candidate >= i:
            continue
        else:
            temp += i-candidate
    
    

