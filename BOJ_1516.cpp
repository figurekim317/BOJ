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

int n,m,a[510],c[510],e[510];
vvi ed;
queue<int> b;

void Solve()
{
	cin>>n;
	ed.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
		for(int j; ; )
		{
			cin>>j;
			if(!~j) break;
			ed[j].pb(i);
			a[i]++;
		}
	}
	for(int i=1;i<=n; i++) if(!a[i]) b.push(i);
	while(!b.empty())
	{
		int t=b.front(); b.pop();
		for(auto &i: ed[t])
		{
			c[i]=max(c[i],e[t]+c[t]);
			a[i]--;
			if(!a[i]) b.push(i);
		}
	}
	for(int i=1; i<=n; i++)
		cout<<c[i]+e[i]<<'\n';
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
