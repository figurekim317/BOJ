

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[15][15];
ll ans=-1;

bool chk(ll p)
{
    ll tmp=((ll)sqrt(p))-2;
    for(ll i=tmp;i<=tmp+4;i++)
        if(i*i==p) return true;
    return false;
}

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf(" %c",a[i]+j),a[i][j]-='0';

    for(int x=-n;x<n;x++)
        for(int y=-m;y<m;y++)
        {
            if(!x&&!y) continue;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                {
                    ll tmp=0;
                    for(int p=i,q=j;p>0&&q>0&&p<=n&&q<=m;p+=x,q+=y)
                    {
                        tmp*=10ll; tmp+=(ll)a[p][q];
                        if(chk(tmp)) ans=max(ans,tmp);
                    }
                }
        }
    printf("%lld",ans);
    return 0;
}
