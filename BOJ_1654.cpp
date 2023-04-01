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
vi a;

bool amel(int p)
{
	int cnt = 0;
	for(auto &i: a)
		cnt+= i/p;
	return cnt >= m;
}

void Solve()
{
	cin>>n>>m;
	a.resize(n);
	for(auto &i: a) cin>>i;
	int lf = 1, rg = INT_MAX;
	while(lf<rg)
	{
		int mid = (ll)lf+rg+1 >> 1;
		if(amel(mid)) lf = mid;
		else rg = mid - 1;
	}
	cout<<lf;
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
