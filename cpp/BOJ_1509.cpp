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

int n,m,dp[2510]={1},b[5010];
string a;

void Solve()
{
	cin>>a;
	for(int i=a.size()<<1;i--;)
		for(int j=i&1; i-j>>1>=0&&i+j>>1<a.size(); b[i]=j+=2)
			if(a[i-j>>1]!=a[i+j>>1]) break;
	for(int i=1;i<a.size();i++)
	{
		if(b[i]>i) {dp[i]=1; continue;}
		dp[i]=INT_MAX;
		for(int j=1;j<=i;j++)
			if(b[i+j] > i-j) dp[i]=min(dp[i],dp[j-1]+1);
	}
	cout<<dp[a.size()-1];
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

