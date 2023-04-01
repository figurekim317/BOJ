#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 998244353
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,r[55];
pll a[55];
ll sw[55],sc[55],m;

ll amel(int p, ll nw, ll nc)
{
    if(nw+sw[p]<=m) return nc+sc[p];
    ll ret=amel(r[p]-1,nw,nc);
    for(;;p--)
    {
        nw+=a[p].ff;
        nc+=a[p].ss;
        if(nw>m) break;
        ret=max(ret,amel(r[p]-1,nw,nc));
        if(p==r[p]) break;
    }
    return ret;
}

void Solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].ff>>a[i].ss;
    cin>>m;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sw[i]=sw[i-1]+a[i].ff,sc[i]=sc[i-1]+a[i].ss;
    for(int i=1;i<=n;i++) r[i]=(a[i].ff==a[i-1].ff ? r[i-1] : i);
    cout<<amel(n,0,0);
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}

