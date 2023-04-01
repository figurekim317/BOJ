#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 60010
#define M 100010

int n,m,a[55],ans;
list<int> ed[55];

void dfs(int p)
{
    a[p]=1;
    for(auto i:ed[p]) dfs(i);
}

int main()
{
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0,j;i<n;i++)
    {
        scanf("%d",&j);
        if(~j) ed[j].pb(i);
    }
    cin>>m; dfs(m);
    for(int i=0;i<n;i++) if(!a[i]&&(ed[i].empty()||(ed[i].size()==1&&ed[i].front()==m))) ans++;
    cout<<ans;
    return 0;
}
