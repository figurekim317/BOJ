#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000

ll a[2][2]={1,1,1,0},d[2][2]={1,0,0,1};
ll n;

ll (*mul(ll p[][2],ll q[][2]))[2]
{
    ll (*ret)[2]=new ll[2][2];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            ret[i][j]=0;
            for(int s=0;s<2;s++)
                ret[i][j]+=p[i][s]*q[s][j],
                ret[i][j]%=MOD;
        }
    return ret;
}

ll (*amel(ll p[][2],ll q))[2]
{
    if(!q) return d;
    return q&1ll?mul(p,amel(mul(p,p),q>>1)):amel(mul(p,p),q>>1);
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%lld",&n);
    ll (*ans)[2];
    ans=amel(a,n-1);
    printf("%lld",ans[0][0]);
    return 0;
}
