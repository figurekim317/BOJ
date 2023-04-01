#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 200010
#define MOD 1000000000

int n,m,k,a[N];
set<pii> ed[N];

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int s,e,w; scanf("%d %d %d",&s,&e,&w);
        auto t=ed[s].lower_bound({e,0});
        if(t==ed[s].end()||t->first!=e) ed[s].insert({e,w});
        else if(t->second>w) ed[s].erase(t),ed[s].insert({e,w});
    }
    memset(a,1,sizeof(a));
    priority_queue<pii> dij;
    dij.push({0,k});
    while(!dij.empty())
    {
        auto p=dij.top(); dij.pop();
        if(!(a[p.second]&1<<24)) continue;
        a[p.second]=-p.first;
        for(auto i:ed[p.second])
            if(a[i.first]>a[p.second]+i.second)
                dij.push({-a[p.second]-i.second,i.first});
    }
    for(int i=1;i<=n;i++) a[i]&1<<24?printf("INF\n"):printf("%d\n",a[i]);
    return 0;
}
