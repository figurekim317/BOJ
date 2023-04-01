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
#define MOD 998244353

int n,m;
vi a[3100];

void amel(int p,int q,int r)
{
	if(r==3)
	{
		a[p].pb(q);
		a[p+1].pb(q-1); a[p+1].pb(q+1);
		for(r=q+2,q-=2; q<=r; q++) a[p+2].pb(q);
		return;
	}
	r>>=1;
	amel(p,q,r); amel(p+r,q-r,r); amel(p+r,q+r,r);
}

void Solve()
{
	cin>>n;
	amel(0,n-1,n);
	for(int i=0;i<n;i++,cout<<'\n')
		for(int j=0,k=0;j<=n<<1;j++)
		{
			if(k<a[i].size()&&a[i][k]==j) k++,cout<<'*';
			else cout<<' ';
		}
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
