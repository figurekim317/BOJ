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
#define MOD 998244353

int n,m,a[1'000'10];
vvpii ed;

void dfs(int p)
{
	for(auto &i: ed[p])
		if(!~a[i.ff])
			a[i.ff]=a[p]+i.ss, dfs(i.ff);
}

void Solve()
{
	cin>>n;
	ed.resize(n+1);
	for(int i=n,j,k,r;i--;)
	{
		cin>>r;
		for(;;)
		{
			cin>>j;
			if(!~j) break;
			cin>>k;
			ed[r].pb(mp(j,k));
			ed[j].pb(mp(r,k));
		}
	}
	memset(a,-1,sizeof(a));
	a[1]=0; dfs(1);
	int t=max_element(a+1,a+n+1)-a;
	memset(a,-1,sizeof(a));
	a[t]=0; dfs(t);
	cout<<*max_element(a+1,a+n+1);
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
