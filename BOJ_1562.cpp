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
#define MOD 1'000'000'000

int n,m;
ll a[110][1<<10][10];

void Solve()
{
	cin>>n;
	for(int i=1;i<10;i++) a[1][1<<i][i]=1;
	for(int i=1;i<n;i++)
		for(int r=1<<10;r--;)
			for(int j=10;j--;)
				for(int k:{-1,1})
					if(0<=j+k&&j+k<10)
						a[i+1][r|1<<j+k][j+k]+=a[i][r][j],
						a[i+1][r|1<<j+k][j+k]%=MOD;
	ll ans=0;
	for(int i=10;i--;) ans+=a[n][1023][i],ans%=MOD;
	cout<<ans;
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

