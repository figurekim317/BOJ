






#include <bits/stdc++.h>
using namespace std;

int n,vis[60],mat[60],a[60],num[60];
list<int> e[60];
set<int> ans;

void init()
{
    for(int i=0;i<60;i++) e[i].clear();
    memset(mat,0,sizeof(mat));
    memset(num,0,sizeof(num));
}

int dfs(int p)
{
    if(vis[p]) return 0;
    vis[p]=1;
    for(auto i:e[p])
        if(!mat[i]||dfs(mat[i]))
        {
            mat[i]=p; return 1;
        }
    return 0;
}

bool isprime(int p)
{
    if(!(p&1)) return 0;
    for(int i=3;i*i<=p;i+=2)
        if(p%i==0) return 0;
    return 1;
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=1;i<n;i++)
        if(isprime(a[0]+a[i]))
        {
            init();
            int l=1,r=1;
            for(int j=1;j<n;j++)
                if(i!=j) num[j]=a[j]&1?l++:r++;
            for(int j=1;j<n;j++)
                for(int k=j+1;k<n;k++)
                    if(j!=i&&k!=i&&isprime(a[j]+a[k]))
                        a[j]&1?e[num[j]].push_back(num[k]):e[num[k]].push_back(num[j]);
            int cnt=0;
            for(int j=1;j<l;j++)
            {
                memset(vis,0,sizeof(vis));
                if(dfs(j)) cnt++;
            }
            if(cnt<<1==n-2) ans.insert(a[i]);
        }
    if(ans.empty()) printf("-1");
    else
    {
        for(auto i:ans) printf("%d ",i);
    }
    return 0;
}
