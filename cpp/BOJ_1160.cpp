#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1'000'000'009

//int n,m;
ll n,m,a,c,x,g;

ll mymul(ll p,ll q)
{
    ll ret=0;
    for(;p;p/=10)
    {
        ret+=q*(p%10)%m;
        ret%=m;
        q=(q*5%m)*2%m;
    }
    return ret;
}

ll mypow(ll p,ll q)
{
    if(!q) return 1;
    if(~q&1ll) return mypow(mymul(p,p),q>>1);
    return mymul(mypow(mymul(p,p),q>>1),p);
}

ll myadd(ll lf,ll rg)
{
    if(lf==rg) return mypow(a,lf);
    ll mid=lf+rg-1>>1;
    ll ret=(mypow(a,mid-lf+1)+1)%m;
    return ((((lf^rg)&1ll)?0:mypow(a,rg))+mymul(ret,myadd(lf,mid)))%m;
}

void Solve()
{
    cin>>m>>a>>c>>x>>n>>g;
    ll ans=mymul(mypow(a,n),x);
    cout<<(ans+mymul(c,myadd(0,n-1)))%m%g;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//    int tc; cin>>tc; for(int i=1;i<=tc;i++)
//    cout<<"Case #"<<i<<'\n',
    Solve();
    return 0;
}
