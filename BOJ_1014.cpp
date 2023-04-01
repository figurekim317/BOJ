#include <bits/stdc++.h>
using namespace std;

int n=1,m=1,seat[90][90],vis[3210],mat[3210];
list<int> e[3210];

void init()
{
    n=m=1;
    memset(seat,0,sizeof(seat));
    memset(mat,0,sizeof(mat));
    for(int i=0;i<3210;i++) e[i].clear();
}

int dfs(int p)
{
    if(vis[p]) return 0;
    vis[p]=1;
    for(auto i:e[p])
        if(!mat[i]||dfs(mat[i]))
        {
            mat[i]=p; return 1;
        }
    return 0;
}

int main(){
   // freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    for(int ii=0,s,t;ii<te;ii++,init())
    {
        scanf("%d %d",&s,&t);
        int ans=0;
        for(int i=1;i<=s;i++)
            for(int j=1;j<=t;j++)
            {
                char c;
                scanf(" %c",&c);
                if(c!='x') ans++,seat[i][j]=j&1?n++:-(m++);
            }
        for(int i=1;i<=s;i++)
            for(int j=1;j<=t;j+=2)
                if(seat[i][j])
                {
                    int d[6][2]={0,-1,-1,-1,0,1,-1,1,1,-1,1,1};
                    for(int k=0;k<6;k++)
                    {
                        int tmp=seat[i+d[k][0]][j+d[k][1]];
                        if(tmp) e[seat[i][j]].push_back(-tmp);
                    }
                }
        for(int i=1;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ans--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
