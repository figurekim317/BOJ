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

int n,m,a[300'010],par[300'010];
pii b[300'010];

int parfind(int p)
{
	if(par[p]==p) return p;
	return par[p]=parfind(par[p]);
}

void Solve()
{
	cin>>n>>m;
	for(int i=n;i--;) cin>>b[i].ss>>b[i].ff;
	for(int i=m;i--;) cin>>a[i];
	sort(a,a+m);
	sort(b,b+n);
	for(int i=m+1;i--;) par[i]=i;
	ll ans=0;
	for(int i=n;i--;)
	{
		int r=lower_bound(a,a+m,b[i].ss)-a;
		if(parfind(r)<m) ans+=b[i].ff,par[par[r]]=parfind(par[r]+1);
	}
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
