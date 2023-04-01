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

int n,m,dp[5][5];
vi a;
int b[5][5]={
0x12345678, 2, 2, 2, 2,
0x12345678, 1, 3, 4, 3,
0x12345678, 3, 1, 3, 4,
0x12345678, 4, 3, 1, 3,
0x12345678, 3, 4, 3, 1
};

void Solve()
{
	for(int i; i; )
		cin>>i, a.pb(i);
	a.pop_back();
	memset(dp,0x11,sizeof(dp));
	dp[0][0]=0;
	for(auto &t: a)
	{
		int tmp[5][5];
		memset(tmp,0x11,sizeof(tmp));
		for(int i=5;i--;)
			//dp[i][t]
			for(int j=5;j--;)
				//from dp[i][j]
				tmp[i][t]=min(tmp[i][t], dp[i][j]+b[j][t]),
				//from dp[j][t]
				tmp[i][t]=min(tmp[i][t], dp[j][t]+b[j][i]),
			//dp[t][i]
				//from dp[j][i]
				tmp[t][i]=min(tmp[t][i], dp[j][i]+b[j][t]),
				//from dp[t][j]
				tmp[t][i]=min(tmp[t][i], dp[t][j]+b[j][i]);
		memcpy(dp,tmp,sizeof(dp));
	}
	cout<<*min_element(dp[0], dp[4]+5);
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
