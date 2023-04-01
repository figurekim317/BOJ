#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m,k,c,ans;
pii a[105],dap;

struct cmp
{
    bool operator()(const pii lhs,const pii rhs) const
    {
        if(lhs.ss==rhs.ss) return lhs.ff<rhs.ff;
        return lhs.ss<rhs.ss;
    }
};

set<pii,cmp,allocator<pii> > s;

int main(){
    //freopen("input.txt","r",stdin);
//    int tc; cin>>tc;
    cin>>n>>m>>k>>c;
    for(int i=k;i--;) cin>>a[i].ff>>a[i].ss;
    for(int i=k;i--;) a[i]={a[i].ff-a[i].ss,a[i].ff+a[i].ss};
    for(int i=k;i--;)
        for(int u=a[i].ff;u>a[i].ff-2;u--)
        {
            s.clear();
            int cnt=0;
            for(int j=k;j--;)
                if(u<=a[j].ff&&a[j].ff<=u+c) s.insert(a[j]),cnt++;
            int r=abs(u%2);
            for(auto lf=s.begin(),rg=s.begin();rg!=s.end();++lf)
            {
                while(rg!=s.end()&&rg->ss<=lf->ss+c-(r!=abs(lf->ss%2))) ++rg;
                int t=distance(lf,rg);
                if(ans<t) ans=t,dap={u,lf->ss};
            }
        }
    cout<<max(0,min((dap.ff+dap.ss+c)/2,n))<<' '<<min(max((dap.ss-dap.ff)/2,0),m)<<'\n'<<ans;
    return 0;
}
