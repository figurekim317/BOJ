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
#define MOD 1'000'000'009

int n,m,k;
ll a[10'010][25];
vvpii ed;
priority_queue<pair<ll,pii>> dij;

void Solve()
{
	cin>>n>>m>>k;
	ed.resize(n);
	for(int i,j,c;m--;)
	{
		cin>>i>>j>>c; i--; j--;
		ed[i].pb(mp(j,c));
		ed[j].pb(mp(i,c));
	}
	memset(a,-1,sizeof(a));
	for(int i=0;i<=k;i++) a[0][i]=0;
	dij.push(mp(0ll,mp(0,0)));
	while(!dij.empty())
	{
		auto t=dij.top(); dij.pop();
		if(a[t.ss.ff][t.ss.ss]!=-t.ff) continue;
		for(auto &i:ed[t.ss.ff])
		{
			if(!~a[i.ff][t.ss.ss]||a[i.ff][t.ss.ss]>-t.ff+i.ss)
				a[i.ff][t.ss.ss]=-t.ff+i.ss, dij.push(mp(t.ff-i.ss,mp(i.ff,t.ss.ss)));
			if(t.ss.ss!=k&&(!~a[i.ff][t.ss.ss+1]||a[i.ff][t.ss.ss+1]>-t.ff))
				a[i.ff][t.ss.ss+1]=-t.ff, dij.push(mp(t.ff,mp(i.ff,t.ss.ss+1)));
		}
	}
	ll ans=LLONG_MAX;
	for(int i=0;i<=k;i++) ans=min(ans,a[n-1][i]);
	cout<<ans;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
