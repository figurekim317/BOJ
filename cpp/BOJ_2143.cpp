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

int n,m,r;
vi a,b,c,d;

void Solve()
{
	cin>>r>>n;
	c.resize(n);
	for(auto &i: c) cin>>i;
	cin>>m;
	d.resize(m);
	for(auto &i: d) cin>>i;
	for(int i=n,t=0; i--; t=0)
		for(int j=i+1; j--; )
			t+=c[j], a.pb(t);
	for(int i=m,t=0; i--; t=0)
		for(int j=i+1; j--; )
			t+=d[j], b.pb(t);
	sort(b.begin(),b.end());
	ll ans=0;
	for(auto &i: a)
		ans+=upper_bound(b.begin(),b.end(),r-i)-lower_bound(b.begin(),b.end(),r-i);
	cout<<ans;
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
