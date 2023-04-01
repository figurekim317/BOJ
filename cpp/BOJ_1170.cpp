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

int n,m,par[210],vis[210],a[4'00'10];
vvi ed;

bool chk(int p,int q)
{
	if(a[p*n+q]) return false;
	return a[p*n+q]=a[q*n+p]=1;
}

bool dfs(int p,int pp)
{
	if(~par[p])
	{
//		cout<<p+1<<' '<<pp+1<<'\n';
		for(int i=pp; i!=par[p]; i=par[i])
		{
//			cout<<i+1<<'\n';
			if(vis[i]) return false;
			vis[i]=1;
		}
		return true;
	}
	par[p]=pp;
	bool ret=true;
	for(auto &i: ed[p])
		if(chk(i,p)) ret &= dfs(i,p);
	return ret;
}

void Solve()
{
	cin>>n>>m;
	ed.resize(n);
	for(int i,j;m--;)
		cin>>i>>j,i--,j--,ed[i].pb(j),ed[j].pb(i);
	memset(par,-1,sizeof(par));
	for(int i=n;i--;)
		if(!~par[i]) m+=dfs(i,n);
	cout<<m+1;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}

