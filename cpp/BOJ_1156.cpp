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

int n,m,a1,a2,b1,b2;
vi a;

int amel(int p)
{
    int ret=m*p;
    list<pii> t,tt;
    for(int i=0;i<n;i++)
    {
        if(i>=a2) t.pb(tt.front()),tt.pop_front();
        int j=a[i]-min(a[i],p);
        p-=a[i]-j;
        ret+=j*b1;
        for(;j&&!t.empty();)
        {
            auto &r=t.front();
            if(i-r.ss<a1) break;
            if(r.ff<=j)
                j-=r.ff,t.pop_front();
            else r.ff-=j,j=0;
        }
        ret+=j*(b2-b1);
        for(;j&&!t.empty();)
        {
            auto &r=t.back();
            if(r.ff<=j)
                j-=r.ff,t.pop_back();
            else r.ff-=j,j=0;
        }
        if(j) return INT_MAX;
        tt.pb(mp(a[i],i));
    }
    return ret;
}

void Solve()
{
    cin>>n>>a1>>a2>>b1>>b2>>m;
    if(a1<a2) swap(a1,a2),swap(b1,b2);
    if(b1>b2) a1=a2,b1=b2;
    a.resize(n);
    int lf=1,rg=0;
    for(auto &i:a) cin>>i,rg+=i;
    while(rg-lf>5)
    {
        int m1=(lf*2+rg)/3,m2=(lf+rg*2)/3;
        if(amel(m1)<amel(m2)) rg=m2;
        else lf=m1;
    }
    int ans=INT_MAX;
    for(;lf<=rg;lf++) ans=min(ans,amel(lf));
    cout<<ans;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){Init(01);
//    int tc; cin>>tc; for(int i=1;i<=tc;i++)
//    cout<<"Case #"<<i<<'\n',
    Solve();
    return 0;
}
