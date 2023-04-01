#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ans[10],a[10];

ll mul(ll p,ll r)
{
    if(r<0) return 0;
    ll ret=1;
    while(r--) ret*=p;
    return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%lld",&n);
    ll r=0;
    for(ll i=1;i<=n;i*=10) a[r++]=(n/i)%10;
    r--;

    for(int i=0;i<r;i++) ans[0]+=a[r]*mul(10,r-1)-mul(10,i);
    for(ll i=0,p=1;i<=r;i++,p*=10)
    {
        for(int j=i==r;j<a[i];j++) ans[j]+=mul(10,i);
        for(int j=i==r;j<10;j++) ans[j]+=i*a[i]*mul(10,i-1);
        ans[a[i]]+=n%p+1;
    }

    for(int i=0;i<10;i++) printf("%lld ",ans[i]);
    return 0;
}