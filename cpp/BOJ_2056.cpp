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

int n,m,a[1'00'010],b[1'00'010],d[1'00'010];
vvi ed;
queue<int> c;

void Solve()
{
	cin>>n;
	ed.resize(n+1);
	for(int i=1,k;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j,k=b[i]; k--; ) cin>>j, ed[j].pb(i);
	}
	for(int i=1;i<=n;i++) if(!b[i]) c.push(i);
	while(!c.empty())
	{
		int t=c.front(); c.pop();
		m=max(m,a[t]+d[t]);
		for(auto &i: ed[t])
		{
			b[i]--;
			d[i]=max(d[i],a[t]+d[t]);
			if(!b[i]) c.push(i);
		}
	}
	cout<<m;
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
