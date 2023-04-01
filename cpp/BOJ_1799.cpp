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

int n,m,a[12][12],b[20];

void amel(int p,int q)
{
	if(p>n-1<<1)
	{
		m=max(m,q);
		return;
	}
	q++;
	for(int x= p<n ? 0 : (p-n+1), y= p<n ? p : (n-1); y>=0&&x<n; x++,y--)
	{
		if(m == q +(n-1<<1)-p) return;
		if(a[x][y]&&!b[x-y+n]) b[x-y+n]=1,amel(p+1,q),b[x-y+n]=0;
	}
	return amel(p+1,q-1);
}

void Solve()
{
	cin>>n;
	for(int i=n;i--;)
		for(int j=n;j--;) cin>>a[i][j];
	amel(0,0);
	cout<<m;
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
