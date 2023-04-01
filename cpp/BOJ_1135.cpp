#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n;
vi par;
vector<vi> ed;

int dfs(int p)
{
    if(ed[p].empty()) return 0;
    vi tmp;
    for(auto i:ed[p]) tmp.pb(dfs(i));
    sort(tmp.begin(), tmp.end());
    int ret=0;
    for(int i=tmp.size();i--;) ret=max(ret, tmp[i]+(int)tmp.size()-i);
    return ret;
}

void Solve()
{
    cin>>n;
    par.resize(n);
    ed.resize(n);
    for(auto &i:par) cin>>i;
    for(int i=1; i<n; i++) ed[par[i]].pb(i);
    cout<<dfs(0);
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
