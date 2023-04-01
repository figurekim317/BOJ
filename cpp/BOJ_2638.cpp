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

int n,m,a[110][110],b[110][110],r;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void dfs(int x,int y)
{
	for(int i=4; i--; )
	{
		int p=x+dx[i], q=y+dy[i];
		if(0<=p&&p<n&&0<=q&&q<m)
		{
			b[p][q]++;
			if(b[p][q]==1 && !a[p][q]) dfs(p,q);
		}
	}
}

void Solve()
{
	cin>>n>>m;
	for(int i=n; i--;)
		for(int j=m; j--;) cin>>a[i][j], r+=a[i][j];
	int ans=0;
	for(; r; ans++)
	{
		memset(b,0,sizeof(b));
		dfs(0,0);
		for(int i=n; i--;)
			for(int j=m; j--;)
				if(a[i][j]&&b[i][j]>1) r--,a[i][j]=0;
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
