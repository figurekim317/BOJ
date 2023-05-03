


#include <bits/stdc++.h>
using namespace std;

int n,m,a[1010],deg[1010],ans[1010];
vector<int> child[1010];

void init()
{
    for(int i=0;i<1010;i++)
        ans[i]=a[i]=deg[i]=0,child[i].clear();
}

int main(){
    //freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    for(int i=0,w;i<te;i++)
    {
        init();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        for(int i=0,s,t;i<m;i++)
            scanf("%d %d\n",&s,&t),child[s].push_back(t),deg[t]++;
        scanf("%d",&w);

        queue<int> q;
        for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
        while(!q.empty())
        {
            int t=q.front(); q.pop();
            ans[t]+=a[t];
            for(auto i:child[t])
            {
                ans[i]=max(ans[i],ans[t]),deg[i]--;
                if(!deg[i]) q.push(i);
            }
        }

        printf("%d\n",ans[w]);
    }
    return 0;
}
