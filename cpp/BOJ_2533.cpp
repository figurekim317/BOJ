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

int n,m,a[1'000'010][2];
vvi ed;

void dfs(int p,int pp)
{
	for(auto &i: ed[p])
		if(i!=pp) dfs(i,p),a[p][1]+=a[i][0],a[p][0]+=min(a[i][0],a[i][1]);
	a[p][0]++;
}

void Solve()
{
	cin>>n;
	ed.resize(n+1);
	for(int i,j,k=n-1;k--;)
		cin>>i>>j,ed[i].pb(j),ed[j].pb(i);
	dfs(1,1);
	cout<<min(a[1][0],a[1][1]);
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

