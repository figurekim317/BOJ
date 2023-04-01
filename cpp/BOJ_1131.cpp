#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,k,d[10],a[7'000'000];
vi c;

int amel(int p)
{
    int ret=0;
    for(;p;p/=10) ret+=d[p%10];
    return ret;
}

void Solve()
{
    cin>>n>>m>>k;
    for(int i=10;i--;)
    {
        d[i]=1;
        for(int j=k;j--;) d[i]*=i;
    }

    for(int i=1; i<=m; i++)
        if(!a[i])
        {
            c.clear();
            c.pb(i); a[i]=-1;
            for(int j=amel(i);;j=amel(j))
            {
                if(a[j]>0)
                {
                    int r=a[j];
                    for(auto t=c.end(); t!=c.begin();)
                    {
                        --t;
                        r=min(r, *t);
                        a[*t]=r;
                    }
                    break;
                }
                if(!~a[j])
                {
                    auto t=c.begin();
                    while(*t!=j) ++t;
                    int r = *min_element(t, c.end());
                    for(auto w=t; w!=c.end(); ++w) a[*w]=r;
                    for(; ; --t)
                    {
                        r=min(r, *t);
                        a[*t]=r;
                        if(t==c.begin()) break;
                    }
                    break;
                }
                a[j]=-1;
                c.pb(j);
            }
        }

    ll ans=0;
    for(int i=n;i<=m;i++) ans+=a[i];
    cout<<ans;
}

int main(){
 //   freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
