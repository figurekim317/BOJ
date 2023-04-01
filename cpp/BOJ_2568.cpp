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
#define MOD 1'000'000'003

int n,m,c[100'010],d[100'010];
pii a[100'010];
vi b;

void Solve()
{
	cin>>n;
	for(int i=n;i--;) cin>>a[i].ff>>a[i].ss;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		auto t=lower_bound(b.begin(),b.end(),a[i].ss);
		c[i]=t-b.begin();
		if(t==b.end()) b.pb(a[i].ss);
		else *t=a[i].ss;
	}
	cout<<n-b.size()<<'\n';
	for(int i=n,j=b.size()-1;i--;)
		if(c[i]==j) j--,d[i]=1;
	for(int i=0;i<n;i++) if(!d[i]) cout<<a[i].ff<<'\n';
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

