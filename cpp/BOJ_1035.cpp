#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 55
#define MOD 1000000007

int n,is[5][5],m[5][5],vis[5][5],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void makemap(int p)
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            m[i][j]=p&1,p>>=1;
}

int makeint()
{
    int ret=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(m[i][j]) ret|=1<<i*5+j;
    return ret;
}

bool inrange(int x,int y,int p)
{
    return x>=0&&x<5&&y>=0&&y<5&&m[x][y]==p;
}

int dfs(int x,int y)
{
    if(vis[x][y]) return 0;
    vis[x][y]=1;
    int ret=1;
    for(int i=0;i<4;i++)
        if(inrange(x+dx[i],y+dy[i],1)) ret+=dfs(x+dx[i],y+dy[i]);
    return ret;
}

bool chk(int p)
{
    makemap(p);
    int x,y;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(m[i][j]) x=i,y=j;
    memset(vis,0,sizeof(vis));
    return dfs(x,y)==n;
}

int nextpath(int p,int ed[])
{
    makemap(p);
    int cnt=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(m[i][j])
                for(int s=0;s<4;s++)
                    if(inrange(i+dx[s],j+dy[s],0))
                    {
                        m[i][j]=0; m[i+dx[s]][j+dy[s]]=1;
                        ed[cnt++]=makeint();
                        m[i][j]=1; m[i+dx[s]][j+dy[s]]=0;
                    }
    return cnt;
}

int amel(int v)
{
    queue<pii> bfs;
    set<int> vis;
    bfs.push({v,0}); vis.insert(v);
    while(!bfs.empty())
    {
        pii p=bfs.front(); bfs.pop();
        if(chk(p.first)) return p.second;
        int ed[25];
        int idx=nextpath(p.first,ed);
        for(int i=0;i<idx;i++)
            if(vis.insert(ed[i]).second) bfs.push({ed[i],p.second+1});
    }
    return -1;
}

int main(){
   // freopen("input.txt","r",stdin);
    int v=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            char s;
            scanf(" %c",&s);
            if(s=='*') n++,v|=1<<5*i+j;
        }
    printf("%d",amel(v));
    return 0;
}
