

nclude <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 55
#define MOD 1000000007

int n,m,k,a[N][N],one[N],vis[N],ans[N];
ll b[N];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%1d",a[i]+j);
    scanf("%d",&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]) one[i]++,b[i]|=1ll<<m-j;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            int cnt=1;
            for(int j=i+1;j<=n;j++)
                if(b[i]==b[j]) vis[j]=1,cnt++;
            ans[m-one[i]]=max(ans[m-one[i]],cnt);
        }
    int dap=0;
    for(;k>=0;k-=2)
        if(k<=m) dap=max(dap,ans[k]);
    printf("%d",dap);
    return 0;
}
