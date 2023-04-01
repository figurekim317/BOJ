#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 110
#define MOD 1000000007
#define SOURCE 0
#define SINK 105

int n,m,a[N][N],now[N][N],work[N],lev[N],r;
vector<int> ed[N];

//bool chk()
//{
//    for(int i:ed[SOURCE])
//        if(now[SOURCE][i]!=a[SOURCE][i]) return 0;
//    for(int i=51;i<=50+m;i++)
//        if(now[i][SINK]!=a[i][SINK]) return 0;
//    return 1;
//}

int dfs(int p,int Mflow)
{
    if(p==SINK) return Mflow;
    for(int &ii=work[p];ii<ed[p].size();ii++)
    {
        int i=ed[p][ii];
        if(lev[i]==lev[p]+1&&a[p][i]>now[p][i])
        {
            int ret=dfs(i,min(Mflow,a[p][i]-now[p][i]));
            if(ret) {now[p][i]+=ret; now[i][p]-=ret; return ret;}
        }
    }
    return 0;
}

bool flow()
{
    memset(now,0,sizeof(now));
    int ret=0;
    while(1)
    {
        memset(work,0,sizeof(work));
        memset(lev,0,sizeof(lev));
        queue<int> bfs;
        bfs.push(SOURCE); lev[SOURCE]=1;
        while(!bfs.empty())
        {
            int p=bfs.front(); bfs.pop();
            if(lev[SINK]) break;
            for(int i:ed[p])
                if(!lev[i]&&a[p][i]>now[p][i])
                    lev[i]=lev[p]+1,bfs.push(i);
        }
        if(!lev[SINK]) break;
        for(int tmp;tmp=dfs(SOURCE,INT_MAX);ret+=tmp) ;
    }
    return ret==r;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    int tmp=0;
    for(int i=1,s;i<=n;i++)
        scanf("%d",&s),a[SOURCE][i]=s,ed[SOURCE].push_back(i),r+=s;
    for(int i=51,s;i<=50+m;i++)
        scanf("%d",&s),a[i][SINK]=s,ed[i].push_back(SINK),tmp+=s;
    for(int i=1;i<=n;i++)
        for(int j=51;j<=50+m;j++)
            a[i][j]=1,ed[i].push_back(j),ed[j].push_back(i);

    if(r!=tmp||!flow()) {printf("-1"); return 0;}
    for(int i=1;i<=n;i++,puts(""))
        for(int j=51;j<=50+m;j++)
        {
            if(!now[i][j]) a[i][j]=0,printf("0");
            else
            {
                a[i][j]=0;
                if(flow()) printf("0");
                else a[i][j]=1,flow(),printf("1");
            }
        }
    return 0;
}
