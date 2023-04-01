#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 10010
#define M 10000010

struct edge
{
    int f,c,v;
    edge *rever;
    edge(){}
    edge(int c1,int v1) {c=c1; v=v1;}
    void flow(int p)
    {
        f+=p; rever->f-=p;
    }
    int spare()
    {
        return c-f;
    }
};

int n,m,b[30],st,ed=5005,ans;
edge *par[5010];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char a[55][55];
list<edge*> edg[5010];

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf(" %c",a[i]+j);
    for(int i=0;i<26;i++) scanf("%d",b+i);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]!='-')
            {
                int t=i*m+j<<1;
                int s=t+1;
                edge *p,*q;
                if(a[i][j]=='*')
                    st=t, p=new edge(MOD,s), q=new edge(0,t);
                else p=new edge(M+b[a[i][j]-'A'],s), q=new edge(0,t);
                p->rever=q; q->rever=p;
                edg[t].pb(p); edg[s].pb(q);
                if(!i||!j||i==n-1||j==m-1)
                {
                    p=new edge(MOD,ed); q=new edge(0,s);
                    p->rever=q; q->rever=p;
                    edg[s].pb(p); edg[ed].pb(q);
                }
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(0<=x&&x<n&&0<=y&&y<m)
                    {
                        p=new edge(MOD,x*m+y<<1); q=new edge(0,s);
                        p->rever=q; q->rever=p;
                        edg[s].pb(p); edg[x*m+y<<1].pb(q);
                    }
                }
            }
    while(1)
    {
        memset(par,0,sizeof(par));
        queue<int> bfs;
        bfs.push(st);
        while(!bfs.empty())
        {
            auto t=bfs.front(); bfs.pop();
            if(t==ed) break;
            for(auto i:edg[t])
                if(!par[i->v]&&i->spare()>0)
                    par[i->v]=i,bfs.push(i->v);
        }
        if(!par[ed]) break;
        int flow=INT_MAX;
        for(auto i=par[ed];i->v!=st;i=par[i->rever->v])
            flow=min(flow,i->spare());
        for(auto i=par[ed];i->v!=st;i=par[i->rever->v])
            i->flow(flow);
        ans+=flow;
    }
    cout<<ans%M;
//    for(int i=0;i<5010;i++)
//        for(auto j:edg[i]) delete j;
    return 0;
}