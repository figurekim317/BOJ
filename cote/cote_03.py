data = input()
cnt1 = 0
cnt2 = 0

for i in range(1, len(data)):
    if int(data[i-1])<int(data[i]):
        cnt1 += 1
    elif int(data[i-1])>int(data[i]):
        cnt2 += 1

print(max(cnt1, cnt2))