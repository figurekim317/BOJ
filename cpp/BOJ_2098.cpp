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

int n,m,a[18][18];
int b[1<<16][16][16];
vvi c;

void Solve()
{
	cin>>n;
	for(int i=n;i--;)
		for(int j=n;j--;) cin>>a[i][j];
	c.resize(n+1);
	for(int i=1<<n,k=0; i--; k=0)
	{
		for(int j=n;j--;) k+=i>>j&1;
		c[k].pb(i);
	}
	for(int i=n;i--;)
		for(int j=n;j--;)
			b[1<<i|1<<j][i][j]=a[i][j]?a[i][j]:INT_MAX;
	for(int k=3;k<=n;k++)
		for(auto &i:c[k])
			for(int s=n;s--;)
				if(i>>s&1)
				{
					for(int e=n;e--;)
						if(e!=s && i>>e&1)
						{
							b[i][s][e]=INT_MAX;
							for(int j=n; j--;)
								if(j!=s&&j!=e&&i>>j&1&&a[j][e]&&b[i^1<<e][s][j]!=INT_MAX)
									b[i][s][e]=min(b[i][s][e], a[j][e]+b[i^1<<e][s][j]);
						}
				}
	int ans=INT_MAX;
	for(int i=n;i--;)
		for(int j=n;j--;)
			if(a[j][i]&&b[(1<<n)-1][i][j]!=INT_MAX)
				ans=min(ans,a[j][i]+b[(1<<n)-1][i][j]);
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

