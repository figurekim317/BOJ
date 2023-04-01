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

int n,m,b[65];
struct node
{
	int x,s,e,r;
	bool operator<(const node &rhs)const
	{
		return x<rhs.x;
	}
};
vector<node> a;
vi c;

int myscan()
{
//	int ret,t;
//	char c;
//	cin>>ret>>c>>t;
//	return ret*10+t;
	double t;
	cin>>t;
	t*=10;
	return (int)t;
}

void Solve()
{
	cin>>n;
	a.resize(n<<1);
	for(int i=n;i--;)
	{
		int x=myscan(),y=myscan(),dx=myscan(),dy=myscan();
		a[i<<1 | 1] = {x,y,y+dy,1};
		a[i<<1] = {x+dx,y,y+dy,-1};
		c.pb(y+dy); c.pb(y);
	}
	sort(a.begin(),a.end());
	sort(c.begin(),c.end());
	c.resize(unique(c.begin(),c.end())-c.begin());
	for(int i=0;i<a.size();)
	{
		int j=i;
		for(;i<a.size() && a[j].x==a[i].x; i++)
			for(int k=0,r=0;k<c.size();k++)
			{
				if(c[k]==a[i].s) r=1;
				if(c[k]==a[i].e) break;
				if(r) b[k]+=a[i].r;
			}
		for(j=0;j<c.size();j++)
			if(b[j]) m+=(a[i].x-a[i-1].x)*(c[j+1]-c[j]);
	}
	if(m%100) cout<<m/100<<'.'<<m%100;
	else cout<<m/100;
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
