def ArrayChallenge(str):
    # __define-ocg__: 이 함수는 문자열 내 아나그램 그룹의 개수를 계산합니다.

    # 문자열을 단어 단위로 분리
    words = str.split()  # 공백을 기준으로 단어 분리
    varOcg = {}  # 아나그램 그룹을 저장할 딕셔너리

    # 각 단어를 정렬된 형태로 변환하여 아나그램 그룹 찾기
    for word in words:
        # 단어를 알파벳 순서로 정렬
        sorted_word = ''.join(sorted(word))
        # 정렬된 단어를 키로 사용하는 딕셔너리에 단어 추가
        if sorted_word in varOcg:
            varOcg[sorted_word].add(word)  # 이미 존재하면 집합에 추가
        else:
            varOcg[sorted_word] = {word}  # 새로 추가
    
    # 아나그램 그룹에서 그룹 크기가 2 이상인 경우를 찾기
    varFiltersCg = [
        group for group in varOcg.values() if len(group) > 1
    ]

    # 결과는 아나그램 그룹의 개수
    return len(varFiltersCg)

# 테스트 케이스
print(ArrayChallenge("aa aa odg dog gdo"))  # Output: 2
print(ArrayChallenge("a c b c run urn urn"))  # Output: 1
