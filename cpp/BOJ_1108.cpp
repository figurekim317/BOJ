#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 3010

int n,m,vis[M];
ll now[M];
vector<string> a;
vector<int> out[M],in[M],use[M];
string c;
queue<int> b;

int strfind(string p)
{
    for(int i=a.size();i--;) if(a[i]==p) return i;
    a.pb(p); return a.size()-1;
}

void dfs(int p)
{
    if(vis[p]) return;
    vis[p]=1;
    for(auto i:out[p]) dfs(i);
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int ii,i;n--;)
    {
        cin>>c>>ii; i=strfind(c);
        for(string j;ii--;) cin>>j,out[strfind(j)].pb(i),in[i].pb(strfind(j));
    }
    cin>>c; m=strfind(c); n=a.size();
    for(int i=n;i--;)
    {
        dfs(i);
        for(auto j:in[i]) if(!vis[j]) use[j].pb(i);
        memset(vis,0,sizeof(vis));
    }
    for(int i=n;i--;)
        for(auto j:use[i]) vis[j]++;
    for(int i=n;i--;)
    {
        if(!vis[i]) b.push(i);
        now[i]=1;
    }
    while(!b.empty())
    {
        int t=b.front(); b.pop();
        if(t==m) {printf("%lld",now[m]); break;}
        for(auto i:use[t])
        {
            now[i]+=now[t];
            vis[i]--;
            if(!vis[i]) b.push(i);
        }
    }
    return 0;
}
