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

int n,m,r,b[1010],a[1010];
vvpii ed,edd;

void dij()
{
	priority_queue<pii> c;
	memset(a,0x44,sizeof(a));
	c.push(mp(0,r)); a[r]=0;
	while(!c.empty())
	{
		auto t=c.top(); c.pop();
		if(-t.ff != a[t.ss]) continue;
		for(auto &i: ed[t.ss])
			if(a[i.ff]>-t.ff+i.ss)
				a[i.ff]=-t.ff+i.ss, c.push(mp(-a[i.ff],i.ff));
	}
}

void Solve()
{
	cin>>n>>m>>r;
	ed.resize(n+1);
	for(int i,j,k; m--; )
	{
		cin>>i>>j>>k;
		ed[i].pb(mp(j,k));
	}
	dij();
	memcpy(b,a,sizeof(a));
	edd=ed;
	for(auto &i: ed) i.clear();
	for(int i=1;i<=n;i++)
		for(auto &j: edd[i]) ed[j.ff].pb(mp(i,j.ss));
	dij();
	for(int i=1;i<=n;i++) b[i]+=a[i];
	cout<<*max_element(b+1,b+n+1);
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
