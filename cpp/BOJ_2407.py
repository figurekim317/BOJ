a, b= input().split()
ans=[]
a=int(a)
b=int(b)
for i in range(a+1):
    ans.append([])
    ans[i].append(1)
    for j in range(1,i+1):
        ans[i].append(ans[i-1][j-1]+ans[i-1][j])
    ans[i].append(0)

print(ans[a][b])