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
#define MOD 1'000'000'009

int n,m,k;

struct amel
{
	int lf,rg,val;
	bool operator<(const amel &rhs)const
	{
		return rg<rhs.rg;
	}
};

vector<amel> a;

struct segtree
{
	int a[20'010<<2],lazy[20'010<<2],siz;
	void init()
	{
		memset(a,0,sizeof(a));
		memset(lazy,0,sizeof(lazy));
		for(siz=1;siz<k;siz<<=1);
	}
	void prop(int pos)
	{
		if(lazy[pos])
		{
			a[pos]+=lazy[pos];
			if(pos<siz) lazy[pos<<1]+=lazy[pos],lazy[pos<<1|1]+=lazy[pos];
			lazy[pos]=0;
		}
	}
	void upd(int lf,int rg,int pos,int nlf,int nrg)
	{
		if(rg<nlf||nrg<lf) return prop(pos);
		if(lf<=nlf&&nrg<=rg)
		{
			lazy[pos]++;
			prop(pos);
			return;
		}
		prop(pos);
		int mid=nlf+nrg>>1;
		upd(lf,rg,pos<<1,nlf,mid); upd(lf,rg,pos<<1|1,mid+1,nrg);
		a[pos]=max(a[pos<<1],a[pos<<1|1]);
	}
	void upd(int lf,int rg){upd(k-rg,k-lf,1,0,siz-1);}
	void bsch()
	{
		n=0;
		prop(1);
		if(a[1]<m) return;
		for(n=1;n<siz;)
		{
			n<<=1;
			prop(n);
			if(m>a[n])
				prop(n|=1);
		}
		n=k-(n^siz);
	}
}b;

void Solve()
{
	cin>>n>>k>>m;
	a.resize(n);
	for(auto &i:a) cin>>i.lf>>i.rg>>i.val;
	sort(a.begin(),a.end());
	n=0;
	b.init();
	int ans=0;
	for(auto &i:a)
		for(;n<i.lf&&i.val;i.val--)
		{
			ans++;
			b.upd(i.lf,i.rg-1);
			b.bsch();
//			cout<<i.lf<<' '<<i.rg<<' '<<i.val<<' '<<n<<'\n';
		}
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
