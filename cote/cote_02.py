data = list(input())
tmp = 0
result = int(data[0])

for i in range(1, len(data)):
    tmp = int(data[i])
    if result==1 or result==0:
        result += tmp
    elif tmp==1 or tmp==0:
        result += tmp
    else:
        result *= tmp

print(result)

# Answer
data = input()
result = int(data[0])

for i in range(1, len(data)):
    num = int(data[i])
    if num<= 1 or result <=1:
        result += num
    else:
        result *= num
    
print(result)

# "~보다 이하" 이 생각을 못해서 놓쳤다..