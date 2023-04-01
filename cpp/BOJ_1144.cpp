#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,a[15][15],ans;
int d[15]={0,1,3,5,7,9,12,15,18,21};
map<int,int> dp, ddp;
vi t;

void upd(vi p, int mynum, int myans)
{
    p.erase(p.begin()); p.pb(mynum);
    int vis[100]={},cnt=0;
    for(auto &i:p)
        if(i)
        {
            if(!vis[i]) vis[i]=++cnt;
            i=vis[i];
        }
    if(cnt<=1) ans=min(ans,myans);
    int ret=0;
    for(int i=m;i--;) ret^=p[i]<<d[i];
    if(!ddp.count(ret)) ddp[ret]=myans;
    else ddp[ret]=min(ddp[ret], myans);
}

void revchg(int p)
{
    for(int i=m;i--;)
        t[i]=(p>>d[i])&((1<<d[i+1]-d[i])-1);
}

void Solve()
{
    cin>>n>>m;
    t.resize(m);
    for(int i=n; i--; )
        for(int j=m; j--; ) cin>>a[i][j];
    dp[0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            ddp.clear();
            for(auto k:dp)
            {
                revchg(k.ff);
                bool flag=!t[0];
                for(int ii=1;!flag&&ii<m;ii++) flag=t[0]==t[ii];
                if(flag) upd(t, 0, k.ss);
                if(!j)
                {
                    upd(t, t[0]?t[0]:m, k.ss+a[i][j]);
                    continue;
                }
                if(t[0]&&t[m-1])
                {
                    for(auto &ii:t) if(ii==t[m-1]) ii=t[0];
                    upd(t, t[0], k.ss+a[i][j]);
                }
                else if(t[0])
                    upd(t, t[0], k.ss+a[i][j]);
                else if(t[m-1])
                    upd(t, t[m-1], k.ss+a[i][j]);
                else
                    upd(t, m, k.ss+a[i][j]);
            }
            dp=ddp;
        }
    cout<<ans;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
