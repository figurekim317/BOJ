#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m,a[55][55],b[55][55],h[2510],cnt,ans[2510];
list<int> par[2510];
int dx[]={0,0,1,-1,1,1,-1,-1},dy[]={1,-1,0,0,1,-1,1,-1};
queue<int> w;
stack<int> r;

bool bound(int p,int q)
{
    return 0<p&&p<=n&&0<q&&q<=m;
}

void numbering(int p,int q)
{
    a[p][q]=cnt;
    for(int i=0;i<8;i++)
        if(bound(p+dx[i],q+dy[i])&&!~a[p+dx[i]][q+dy[i]]) numbering(p+dx[i],q+dy[i]);
}

void flood(int p,int q)
{
    b[p][q]=-1;
    for(int i=0;i<4;i++)
        if(bound(p+dx[i],q+dy[i]))
        {
            int tmp=a[p+dx[i]][q+dy[i]];
            if(tmp&&!h[tmp]) h[tmp]=1,w.push(tmp),r.push(tmp),par[cnt].pb(tmp);
            if(~b[p+dx[i]][q+dy[i]]&&!tmp) flood(p+dx[i],q+dy[i]);
        }
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
             char c;
             cin>>c;
             if(c=='x') a[i][j]=b[i][j]=-1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!~a[i][j]) cnt++,numbering(i,j);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++) if(!i||!j||i==n+1||j==m+1) a[i][j]=2505;
    w.push(2505);
    while(!w.empty())
    {
        int t=w.front(); w.pop();
        cnt=t;
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
                if(a[i][j]==t) flood(i,j);
    }
    while(!r.empty())
    {
        int t=r.top(); r.pop();
        for(auto i:par[t]) h[t]=max(h[t],h[i]+1);
        ans[h[t]]++;
    }
    for(cnt=54;cnt>0&&!ans[cnt];cnt--);
    if(!cnt) {printf("-1"); return 0;}
    for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
    return 0;
}