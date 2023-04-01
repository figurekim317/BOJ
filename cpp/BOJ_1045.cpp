#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 55
#define MOD 1000000007

int n,a[N][N],m,par[N],v;
list<int> ed[N];

int parfind(int p)
{
    if(par[p]==p) return p;
    return par[p]=parfind(par[p]);
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char s; scanf(" %c",&s);
            if(s=='Y') ed[i].push_back(j);
        }
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=n;i++)
        for(int j:ed[i])
            if(!a[i][j]&&parfind(i)!=parfind(j)) v++,m--,a[i][j]=a[j][i]=1,par[parfind(j)]=parfind(i);
    for(int i=1;i<=n;i++)
        for(int j:ed[i]) if(m&&!a[i][j]) m--,a[i][j]=a[j][i]=1;
    if(v!=n-1||m) {printf("-1"); return 0;}
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++) cnt+=a[i][j];
        printf("%d ",cnt);
    }
    return 0;
}
