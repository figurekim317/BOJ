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

int n,m,b[20'000'010],d[110],a[110];
vpii c;

int amel(int p,int pp,int q)
{
	return p+2*min(pp,q);
}

void Solve()
{
	cin>>n;
	for(int i=n,p;i--;)
	{
		cin>>p;
		c.pb(mp(p,i));
		if(i==n-1) {a[i]=p; continue;}
		for(int j=i+1;j<n;j++)
			a[i]=max(a[i],amel(a[j],c[n-1-j].ff,p));
	}
	sort(c.begin(),c.end());
	memset(b,-1,sizeof(b));
	for(int i=n; i--;)
		for(int j=a[c[i].ss]-c[i].ff;j<a[c[i].ss]+c[i].ff;j++)
			if(!~b[j]) b[j]=c[i].ss;
	for(int i=20'000'005;i--;)
		if(~b[i]) d[b[i]]=1;
	for(int i=n;i--;) if(d[i]) cout<<n-i<<' ';
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
