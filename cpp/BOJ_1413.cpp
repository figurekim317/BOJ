#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define N 25
#define M 0
#define MOD 998244853

int n,m,cnt;
pll a[N][N],ans;

pll sum(pll p,pll q)
{
    if(!p.ss) return q;
    ll tmp=__gcd(p.ss,q.ss);
    ll s=p.ss/tmp*q.ff+q.ss/tmp*p.ff,t=p.ss/tmp*q.ss;
    tmp=__gcd(s,t);
    return {s/tmp,t/tmp};
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    a[n][m]={1ll,1ll};
    for(int i=n;i;i--)
        for(int j=m;j;j--)
            if(a[i][j].ss)
                for(int k=0;k<i;k++)
                    a[k][j-1]=sum(a[k][j-1],{a[i][j].ff,a[i][j].ss*i});
    for(int i=0;i<m;i++) ans=sum(ans,a[0][i]);
    printf("%lld/%lld",ans.ff,ans.ss);
    return 0;
}
