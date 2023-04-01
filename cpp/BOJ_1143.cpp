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

int n,ed[55][55],cnt;
vi a, vis, r;
stack<int> scc;
int avghap, avgcnt;

struct node
{
    vi a;
    int w=INT_MAX;
};
vector<node> b;

int dfs(int p)
{
    if(~vis[p]) return vis[p];
    vis[p]=cnt++;
    scc.push(p);

    int ret=vis[p];
    for(int i=n;i--;)
        if(ed[p][i]) ret=min(ret, dfs(i));

    if(ret==vis[p])
    {
        node tmp;
        while(!scc.empty())
        {
            int t=scc.top(); scc.pop();
            tmp.a.pb(t);
            tmp.w=min(tmp.w,a[t]);
            vis[t]=INT_MAX;
            if(t==p) break;
        }
        b.pb(tmp);
    }
    else vis[p]=ret;

    return vis[p];
}

void Solve()
{
    cin>>n;
    a.resize(n);
    vis.resize(n, -1);
    for(auto &i:a) cin>>i;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            char c; cin>>c;
            ed[i][j]=c=='Y';
        }
    for(int i=n;i--;) if(!~vis[i]) dfs(i);
    r.resize(b.size(), 1);
    for(int i=b.size(); i--; )
        for(int j=b.size(); j--; )
            if(i!=j)
            {
                for(auto p:b[i].a)
                    for(auto q:b[j].a)
                        if(ed[p][q]) r[j]=0;
            }
    for(int i=b.size(); i--;)
        if(r[i])
        {
            avghap+=b[i].w;
            avgcnt++;
            for(auto j=a.begin(); j!=a.end(); ++j)
                if(*j==b[i].w)
                    {a.erase(j); break;}
        }
    sort(a.begin(), a.end());
    for(auto i:a)
        if(avghap > i*avgcnt)
            avghap+=i, avgcnt++;
    printf("%.9f",(double)avghap/avgcnt);
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
