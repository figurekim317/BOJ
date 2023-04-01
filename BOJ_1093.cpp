#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n;
pll a[32],b[(1<<16)+10];
ll m,ans=LLONG_MAX;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].ss;
    for(int i=0;i<n;i++) cin>>a[i].ff;
    cin>>m;
    for(int i=0;i<1<<(n>>1);i++)
        for(int j=n+1>>1;i>>(j-(n+1>>1));j++)
            if(i>>(j-(n+1>>1))&1) b[i].ff+=a[j].ff,b[i].ss+=a[j].ss;
    sort(b,b+(1<<(n>>1)));
    for(int i=(1<<(n>>1))-1;i--;) b[i].ss=min(b[i].ss,b[i+1].ss);
    for(int i=0;i<1<<(n+1>>1);i++)
    {
        ll gachi=0,price=0;
        for(int j=0;i>>j;j++)
            if(i>>j&1) gachi+=a[j].ff,price+=a[j].ss;
        auto t=lower_bound(b,b+(1<<(n>>1)),make_pair(m-gachi,0ll));
        if(t!=b&&t->ss==0) continue;
        ans=min(ans,price+t->ss);
    }
    if(ans==LLONG_MAX) {printf("-1"); return 0;}
    cin>>n;
    for(int i;n--;) cin>>i,ans-=a[i].ss;
    cout<<max(ans,0ll);
    return 0;
}