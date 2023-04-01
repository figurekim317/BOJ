#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 998244353
#define N 100000
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,ed[55][55],flow[55][55],vis[55],ans;
list<int> yes[55],no[55];

void Solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%1d",ed[i]+j);
    cin>>m;
    for(int i=0,j;i<n;i++)
    {
        cin>>j;
        for(int s;j--;) cin>>s,yes[s].pb(i);
    }
    for(int i=0,j;i<n;i++)
    {
        cin>>j;
        memset(vis,0,sizeof(vis));
        for(int s;j--;) cin>>s,no[s].pb(i);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            ed[j][SOURCE]=ed[SOURCE][j]=0,ed[j][SINK]=ed[SINK][j]=100;
        for(auto j:yes[i]) ed[j][SOURCE]=ed[SOURCE][j]=100;
        for(auto j:no[i]) ed[j][SINK]=ed[SINK][j]=0;
        memset(flow,0,sizeof(flow));
        while(1)
        {
            queue<int> bfs;
            bfs.push(SOURCE);
            memset(vis,-1,sizeof(vis));
            vis[SOURCE]=SOURCE;
            while(!bfs.empty())
            {
                int t=bfs.front(); bfs.pop();
                if(t==SINK) break;
                for(int j=0;j<=SINK;j++)
                    if(!~vis[j]&&flow[t][j]<ed[t][j]) bfs.push(j),vis[j]=t;
            }
            if(!~vis[SINK]) break;
            int w=INT_MAX;
            for(int j=SINK;j!=SOURCE;j=vis[j])
                w=min(w,ed[vis[j]][j]-flow[vis[j]][j]);
            for(int j=SINK;j!=SOURCE;j=vis[j])
                flow[vis[j]][j]+=w,flow[j][vis[j]]-=w;
            ans+=w;
        }
    }
    cout<<ans;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}

