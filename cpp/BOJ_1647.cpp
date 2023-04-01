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

int n,m,par[1'00'010];

struct edge
{
	int s,e,w;
	bool operator<(const edge rhs)const
	{
		return w<rhs.w;
	}
};
vector<edge> ed;

int parfind(int p)
{
	if(par[p]==p) return p;
	return par[p]=parfind(par[p]);
}

bool uni(int p,int q)
{
	p=parfind(p); q=parfind(q);
	if(p==q) return false;
	par[q]=p;
	return true;
}

void Solve()
{
	cin>>n>>m;
	ed.resize(m);
	for(auto &i: ed) cin>>i.s>>i.e>>i.w;
	sort(ed.begin(),ed.end());
	for(int i=1; i<=n; i++) par[i]=i;
	int cnt=n-2;
	ll ans=0;
	for(auto &i: ed)
	{
		if(uni(i.s,i.e)) ans+=i.w, cnt--;
		if(!cnt) {cout<<ans; return;}
	}
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
