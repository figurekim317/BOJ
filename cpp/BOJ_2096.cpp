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

int n,m,a[2][2][3];

void Solve()
{
	cin>>n;
	for(int x,y,z; n--; )
	{
		cin>>x>>y>>z;
		a[0][n&1][0]=x+max(a[0][n+1&1][0],a[0][n+1&1][1]);
		a[0][n&1][1]=y+*max_element(a[0][n+1&1], a[0][n+1&1]+3);
		a[0][n&1][2]=z+max(a[0][n+1&1][1],a[0][n+1&1][2]);
		a[1][n&1][0]=x+min(a[1][n+1&1][0],a[1][n+1&1][1]);
		a[1][n&1][1]=y+*min_element(a[1][n+1&1], a[1][n+1&1]+3);
		a[1][n&1][2]=z+min(a[1][n+1&1][1],a[1][n+1&1][2]);
	}
	cout<<*max_element(a[0][0], a[0][0]+3)<<' '<<
		*min_element(a[1][0], a[1][0]+3);
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
