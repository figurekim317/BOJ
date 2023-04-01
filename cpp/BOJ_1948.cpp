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

int n,m,s,e,a[10'010],b[10'010];
vvpii ed,c;

void Solve()
{
	cin>>n>>m;
	ed.resize(n+1);
	c.resize(n+1);
	for(int i,j,k;m--;)
		cin>>i>>j>>k, ed[i].pb(mp(j,-k)),c[j].pb(mp(i,-k));
	cin>>s>>e;
	memset(a,-1,sizeof(a));
	priority_queue<pii> dij;
	dij.push(mp(0,s)); a[s]=0;
	while(!dij.empty())
	{
		auto t=dij.top(); dij.pop();
		if(a[t.ss]!=-t.ff) continue;
		for(auto &i: ed[t.ss])
			if(!~a[i.ff] || a[i.ff]>i.ss-t.ff)
				a[i.ff]=i.ss-t.ff, dij.push(mp(-a[i.ff],i.ff));
	}
	cout<<-a[e]<<'\n';
	queue<int> bfs;
	bfs.push(e); b[e]=1;
	m=0;
	while(!bfs.empty())
	{
		auto t=bfs.front(); bfs.pop();
		for(auto i:c[t])
			if(a[i.ff]==a[t]-i.ss)
			{
				m++;
				if(!b[i.ff]) b[i.ff]=1, bfs.push(i.ff);
			}
	}
	cout<<m;
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
