def solution(words, queries):
    answer = []
    return answer

'''words를 먼저 글자 수를 기준으로 정렬하고 사전 배열 식으로 정렬


queries에 있는 단어와 ?가 나오는 index 부터 끝나는 인덱스까지 전까지 단어가 일치하는지 체크하는 함수
1. 체크했을 때 문자열이 일치하고 ???의 개수와 남은 문자열의 수가 같다면 count 증가
'''

from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.count = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            node = node.children[char]
            node.count += 1

    def search(self, query):
        node = self.root
        for char in query:
            if char == '?':
                return node.count
            if char not in node.children:
                return 0
            node = node.children[char]
        return 0

def solution(words, queries):
    answer = []
    
    # 단어를 길이별로 분류
    words_by_length = defaultdict(list)
    for word in words:
        words_by_length[len(word)].append(word)
    
    # Trie와 역방향 Trie 생성
    tries = defaultdict(Trie)
    reverse_tries = defaultdict(Trie)
    
    for length, word_list in words_by_length.items():
        for word in word_list:
            tries[length].insert(word)
            reverse_tries[length].insert(word[::-1])
    
    # 쿼리 처리
    for query in queries:
        length = len(query)
        if query[0] == '?':  # 접두사가 '?'
            search_query = query[::-1]
            answer.append(reverse_tries[length].search(search_query))
        else:  # 접미사가 '?'
            answer.append(tries[length].search(query))
    
    return answer
