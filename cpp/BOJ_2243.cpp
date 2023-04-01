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

int n,m,a[3'000'010];

void upd(int pos,int p)
{
	a[pos|=m]+=p;
	for(pos>>=1;pos;pos>>=1) a[pos]+=p;
}

int amel(int p)
{
	int ret=1;
	for(; ~ret&m; )
	{
		if(a[ret<<1] < p)
			p-=a[ret<<=1],ret|=1;
		else ret<<=1;
	}
	upd(ret^=m,-1);
	return ret;
}

void Solve()
{
	cin>>n;
	for(m=1;m<1'000'000;m<<=1);
	for(int i,j,k;n--;)
	{
		cin>>i>>j;
		if(i&1)
			cout<<amel(j)+1<<'\n';
		else
		{
			cin>>k;
			upd(j-1,k);
		}
	}
}

void Init(bool isLocal=0){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(1);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
