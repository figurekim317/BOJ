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
vi a;
int ans=INT_MAX;
pii dap;

void amel(int p, int q)
{
	if(p!=q && ans>abs(p+q))
	{
		ans=abs(p+q);
		if(p<q) dap=mp(p,q);
		else dap=mp(q,p);
	}
}

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	for(auto &i: a)
	{
		auto t=lower_bound(a.begin(),a.end(),-i);
		if(t!=a.end()) amel(i,*t);
		if(t!=a.begin()) --t, amel(i,*t);
	}
	cout<<dap.ff<<' '<<dap.ss;
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
