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

int n,m,ans,b[30],r;
char a[25][25];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void amel(int p, int q)
{
	if(p<0||p>=n||q<0||q>=m) return;
	if(b[a[p][q]-'A']) return;
	b[a[p][q]-'A']=1; r++; ans=max(ans,r);
	for(int i=4; i--; ) amel(p+dx[i],q+dy[i]);
	b[a[p][q]-'A']=0; r--;
}

void Solve()
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		string t; cin>>t;
		for(int j=0; j<m; j++) a[i][j]=t[j];
	}
	amel(0,0);
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
