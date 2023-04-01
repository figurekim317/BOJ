#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 40
#define MOD 1000000007

int n;
ll a[40],b[40];
pll ans={LLONG_MAX,0};
set<pll> rg[25];

void upd(ll p,ll q)
{
    if(ans.first>p||(ans.first==p&&ans.second>q))
        ans={p,q};
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    for(int i=0;i<n;i++) scanf("%lld",b+i);
    n>>=1;
    for(ll i=0;i<1ll<<n;i++)
    {
        ll cnt=(ll)n,tmp=0;
        for(int j=0;j<n;j++)
        {
            if(i>>j&1ll) cnt--,tmp-=b[(n<<1)-j-1];
            else tmp+=a[(n<<1)-j-1];
        }
        rg[cnt].insert({tmp,i});
    }
    for(ll i=0;i<1ll<<n;i++)
    {
        ll cnt=0,tmp=0;
        for(int j=0;j<n;j++)
        {
            if(i>>j&1ll) cnt++,tmp-=b[n-j-1];
            else tmp+=a[n-j-1];
        }
        auto t=rg[cnt].lower_bound({-tmp,0ll});
        if(t!=rg[cnt].end())
            upd(t->first+tmp,i<<n|t->second);
        if(t!=rg[cnt].begin())
        {
            t--;
            t=rg[cnt].lower_bound({t->first,0ll});
            upd(-tmp-t->first,i<<n|t->second);
        }
    }
    for(int i=0;i<n<<1;i++) printf(ans.second>>((n<<1)-i-1)&1ll?"2 ":"1 ");
    return 0;
}
