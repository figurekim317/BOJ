#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1'000'000'007

int n,m,lev[40'010];
vvpii ed;
pii par[19][40'010];

void dfs(int p,int pp,int now)
{
	lev[p]=now++;
	for(auto &i:ed[p])
		if(i.ff!=pp)
			par[0][i.ff]=mp(p,i.ss),
			dfs(i.ff,p,now);
}

int lca(int p,int q)
{
	int ret=0;
	if(lev[p]<lev[q]) swap(p,q);
	for(int i=19;i--;)
		if(lev[p]-lev[q]>>i&1)
			ret+=par[i][p].ss,
			p=par[i][p].ff;
	if(p==q) return ret;
	for(int i=19; i--;)
		if(par[i][p].ff!=par[i][q].ff)
			ret+=par[i][p].ss+par[i][q].ss,
			p=par[i][p].ff,
			q=par[i][q].ff;
	return ret+par[0][p].ss+par[0][q].ss;
}

void Solve()
{
	cin>>n;
	ed.resize(n+1);
	for(int i,j,k,r=n-1;r--;)
		cin>>i>>j>>k, ed[i].pb(mp(j,k)),ed[j].pb(mp(i,k));
	dfs(1,1,0);
	par[0][1]=mp(1,0);
	for(int i=1;i<19;i++)
		for(int j=1;j<=n;j++)
		{
			auto t=par[i-1][j];
			auto r=par[i-1][t.ff];
			par[i][j]=mp(r.ff,r.ss+t.ss);
		}
	cin>>m;
	for(int i,j;m--;)
	{
		cin>>i>>j;
		cout<<lca(i,j)<<'\n';
	}
}

void Init(bool isLocal=0){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(1);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
