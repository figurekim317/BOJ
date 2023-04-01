#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

ll n;
map<ll,ll> ans;

ll sng(ll p,ll q)
{
    if(!q) return 1;
    return 1ll&q?p*sng(p*p,q>>1):sng(p*p,q>>1);
}

ll por(ll p,ll q)
{
    ll t=(ll)pow((double)p,(double)1/q);
    t-=2; t=max(t,1ll);
    while(pow(t+1,q)<(double)LLONG_MAX-5&&sng(t+1,q)<=p) t++;
    return t;
}

ll aabs(ll p)
{
    return p>0?p:-p;
}

void amel(ll p)
{
    if(ans.find(p)!=ans.end()) return;
    ll ret=LLONG_MAX;
    for(ll i=2;p>>i-1;i++)
    {
        auto t=por(p,i);
        if(ans.find(t)==ans.end()) amel(t);
        if(ans.find(t+1)==ans.end()) amel(t+1);
        if(pow(t,i)<(double)(n<<1)) ret=min(ret,ans[t]+aabs(sng(t,i)-p));
        if(pow(t+1,i)<(double)(n<<1)) ret=min(ret,ans[t+1]+aabs(sng(t+1,i)-p));
//        printf("%lld, %d: %d\n",p,i,ret);
    }
    ans[p]=ret+1;
//    printf("%lld: %d\n",p,ans[p]);
}

int main()
{
   // freopen("input.txt","r",stdin);
    cin>>n;
    ans[1]=0;
    ans[2]=1;
    ans[3]=2;
    amel(n); cout<<ans[n];
//    for(int i=1;i<=30;i++) amel(i),cout<<i<<": "<<ans[i]<<'\n';
    return 0;
}
