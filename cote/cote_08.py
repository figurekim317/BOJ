# 내림 차순으로 정리하는 것을 놓침
# 알파벳인지 수자인지를 분간할 수 있는

n = input()
result = []
value = 0

for x in n:
    if x.isalpha():
        result.append(x)
    else:
        value += int(x)

result.sort()

if value != 0:
    result.append(str(value)) # 숫자로는 10단위가 넘어가면 append가 안됨!

print(''.join(result)) # 빈칸없이 숫자와 문자를 합치는 방법


