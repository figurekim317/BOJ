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

struct amel
{
	int a,b,c;
	amel(){}
	amel(int aa,int bb,int cc)
	{
		a=aa; b=bb; c=cc;
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
	}
	bool operator<(const amel &rhs)const
	{
		return abs((ll)a+b+c)<abs((ll)rhs.a+rhs.b+rhs.c);
	}
}ans;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	sort(a.begin(),a.end());
	ans.a=ans.b=ans.c=INT_MAX;
	for(int i=n; i--;)
		for(int j=i; j--;)
		{
			auto t=lower_bound(a.begin(),a.end(),-a[i]-a[j]);
			if(t!=a.end() && *t!=a[i] && *t!=a[j])
				ans=min(ans,amel(a[i],a[j],*t));
			if(t!=a.begin())
			{
				--t;
				if(*t!=a[i]&&*t!=a[j])
					ans=min(ans,amel(a[i],a[j],*t));
			}
		}
	cout<<ans.a<<' '<<ans.b<<' '<<ans.c;
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
