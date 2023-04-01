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
#define MOD 2'001'000'000'00

int n,m,k;
ll b[2010][2010];
pii c[2010];
string a;

void amel(ll &p,ll q)
{
	if(q>>63&1ll) q=~q,p=~p;
	if(p>>63&1ll) p=~((q + ~p)%MOD);
	else if(p+q < MOD) p+=q;
	else p=~((p+q)%MOD);
}

void Solve()
{
	cin>>n>>m>>k>>a;
	for(int i=1;i<=n;i++)
	{
		int t=0,lf=max(0,i-m),rg=min(i+m,n);
		for(int j=0;j<lf;j++) t+=a[j]=='1';
		c[i].ff=t; c[i].ss=i-(lf-t);
		for(int j=lf;j<rg;j++) t+=a[j]=='1';
		c[i].ff=max(c[i].ff, i-(rg-t));
		c[i].ss=min(c[i].ss, t);
	}
	int cnt=0;
	for(auto &i:a) cnt+=i=='1';
	b[n][cnt]=1;
	for(int i=n; i--; )
		for(int j=c[i+1].ff;j<=c[i+1].ss;j++)
			amel(b[i][j],b[i+1][j]),
			amel(b[i][j-1],b[i+1][j]);
	cout<<max(b[0][0],~b[0][0])%100'000'000ll<<'\n';

	for(int i=1,j=0,t=0;i<=n;i++)
	{
		for(t=max(j,c[i].ff); ~b[i][t]>>63&1ll && b[i][t]<(ll)k; t++)
			k-=b[i][t];
		cout<<(j==t?'0':'1');
		j=t;
	}
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

