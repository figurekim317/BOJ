#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 1000000007

int n,m,a[10],len,same,ans,vis[N];

void makearr(int p)
{
    for(len=0;p;p/=10) a[len++]=p%10;
}

int makeint()
{
    int ret=0;
    for(int i=len-1;i>=0;i--) ret*=10,ret+=a[i];
    return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    if(n<10||(n<100&&n%10==0)) {printf("-1"); return 0;}
    makearr(n);
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++) if(a[i]==a[j]) same=1;

    memset(vis,-1,sizeof(vis));
    queue<int> bfs;
    bfs.push(n); vis[n]=0;
    while(!bfs.empty())
    {
        int p=bfs.front(); bfs.pop();
        if(vis[p]>m) break;
        if(same||!(m-vis[p]&1)) ans=max(ans,p);
        makearr(p);
        for(int i=0;i<len;i++)
            for(int j=i+1;j<len;j++)
                if(j!=len-1||a[i])
                {
                    swap(a[i],a[j]);
                    int tmp=makeint();
                    if(vis[tmp]<0) bfs.push(tmp),vis[tmp]=vis[p]+1;
                    swap(a[i],a[j]);
                }
    }
    printf("%d",ans);
    return 0;
}
