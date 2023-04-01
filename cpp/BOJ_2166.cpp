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

int n,m;
vpii a;

pii mysub(pii p, pii q)
{
	return mp(p.ff-q.ff, p.ss-q.ss);
}

ll amel(pii p, pii q)
{
	return (ll)p.ss*q.ff - (ll)p.ff*q.ss;
}

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i.ff>>i.ss;
	ll ans=0;
	for(int i=1; i<n-1; i++)
		ans+=amel(mysub(a[i],a.front()),mysub(a[i+1],a.front()));
	cout<<(abs(ans)>>1)<<'.';
	cout<<(ans&1ll ? '5' : '0');
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
