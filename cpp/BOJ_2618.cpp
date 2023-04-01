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

int n,m,dp[1'010][1'010][2],par[1'010][2],b[1'010];
vpii a;

int amel(int p,int q)
{
	return abs(a[p].ff-a[q].ff)+abs(a[p].ss-a[q].ss);
}

bool upd(int &p,int q,int r)
{
	if(!~q) return false;
	if(!~p || p>q+r) {p=q+r; return true;}
	return false;
}

void Solve()
{
	cin>>n>>m;
	a.pb(mp(1,1)); a.pb(mp(n,n));
	for(int i,j,k=m;k--;) cin>>i>>j,a.pb(mp(i,j));
	memset(dp,-1,sizeof(dp));
	dp[1][0][1]=0;
	for(int i=2;i<m+2;i++)
	{
		for(int j=0;j<i-1;j++)
			for(int k:{0,1})
				upd(dp[i][j][k],dp[i-1][j][k],amel(i,i-1));
		for(int j=0;j<i-1;j++)
			for(int k:{0,1})
				if(upd(dp[i][i-1][k],dp[i-1][j][!k],amel(i,j)))
					par[i][k]=j;
	}
	int ans=-1;
	pii r;
	for(int i=m+1;i--;)
		for(int j:{0,1}) if(upd(ans,dp[m+1][i][j],0)) r=mp(i,j);
	cout<<ans<<'\n';
	int p=m+1,q=r.ff;
	if(r.ss) swap(p,q);
	for(;;)
	{
		for(int t=q>p; abs(p-q)>1; )
			b[max(p,q)]=t, q>p?q--:p--;
		b[max(p,q)]=q>p;
		if(!min(p,q)) break;
		if(q>p) q=par[q][1];
		else p=par[p][0];
	}
	for(int i=2;i<m+2;i++) cout<<b[i]+1<<'\n';
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
