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

struct seg
{
	int a[30'010],siz;
	void init(int p)
	{
		for(siz=1;siz<p;siz<<=1);
		for(int i=p;i--;) a[siz|i]=1;
		for(int i=siz;i--;) a[i]=a[i<<1]+a[i<<1|1];
	}
	void upd(int p)
	{
		for(p|=siz;p;p>>=1) a[p]--;
	}
	int query(int p)
	{
		int ret=1;
		for(;ret<siz;)
		{
			if(a[ret<<1]<p) p-=a[ret<<1],ret=ret<<1|1;
			else ret<<=1;
		}
		return ret^siz;
	}
	int sum(int p)
	{
		int lf=siz,rg=p|siz,ret=0;
		while(lf<rg)
		{
			if(lf&1) ret+=a[lf++];
			else if(~rg&1) ret+=a[rg--];
			else lf>>=1,rg>>=1;
		}
		return ret+a[lf];
	}
}a;

void Solve()
{
	cin>>n>>m;
	a.init(n);
	cout<<"<"<<m;
	a.upd(m-1);
	for(int i=n-1,j=m-1;i--;)
	{
		cout<<", ";
		int t=a.sum(j);
		j=a.query((t+m-1)%a.a[1]+1);
		cout<<j+1;
		a.upd(j);
	}
	cout<<">";
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

