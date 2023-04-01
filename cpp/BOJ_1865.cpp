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

int n,m,r,a[510];
vvpii ed;

bool amel()
{
	bool ret=false;
	int tmp[510];
	memcpy(tmp,a,sizeof(a));
	for(int i=1;i<=n;i++)
		for(auto &j: ed[i])
			if(tmp[i]>a[j.ff]+j.ss)
				ret=true, tmp[i]=a[j.ff]+j.ss;
	memcpy(a,tmp,sizeof(a));
	return ret;
}

void Solve()
{
	cin>>n>>m>>r;
	ed.resize(n+1);
	for(auto &i: ed) i.clear();
	for(int i,j,k; m--; )
	{
		cin>>i>>j>>k;
		ed[i].pb(mp(j,k));
		ed[j].pb(mp(i,k));
	}
	for(int i,j,k; r--; )
	{
		cin>>i>>j>>k;
		ed[i].pb(mp(j,-k));
	}
	memset(a,0x44,sizeof(a));
	a[1]=0;
	for(int i=n-1;i--;) amel();
	cout<<(amel()?"YES\n":"NO\n");
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
