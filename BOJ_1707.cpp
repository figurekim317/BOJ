#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 20010
#define M 0
#define MOD 15746

int n,m,a[N];
list<int> ed[N];

bool dfs(int p,int now)
{
    if(a[p]) return a[p]==now;
    a[p]=now;
    for(int i:ed[p])
        if(!dfs(i,-now)) return 0;
    return 1;
}

int main(){
  //  freopen("input.txt","r",stdin);
    int te; cin>>te;
    while(te--)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++) ed[i].clear();
        cin>>n>>m;
        int s,t,flag=1;
        while(m--) cin>>s>>t,ed[s].push_back(t),ed[t].push_back(s);
        for(int i=1;i<=n;i++)
            if(!a[i]&&!dfs(i,1)) {printf("NO\n"); flag=0; break;}
        if(flag) printf("YES\n");
    }
    return 0;
}
