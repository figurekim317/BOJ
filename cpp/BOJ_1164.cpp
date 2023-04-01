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

int n,m,a[110][110];
int A[5][2]={0,3, 1,0, 1,1, 1,2, 1,3};

bool lookup(int x,int y)
{
	int t=y-1;
	for(; t>=0 && a[x][t]<=0; t--) ;
	for(t++; t<y; t++)
	{
		if(!~a[x][t]) continue;
		if(t==y-1) return false;
		if(!~a[x][t+1])
		{
			if(x==n-1 || t>y-4 || !a[x][t+2] || !~a[x][t+3]) return false;
			t+=3;
		}
		else t++;
	}
	return true;
}

bool chk(int x,int y,bool r)
{
	if(r)
	{
		if(x==n-1 || y>m-4) return false;
		for(int i=5; i--; )
			if(a[x+A[i][0]][y+A[i][1]]) return false;
		return a[x][y+1]==a[x][y+2] && lookup(x+1,y);
	}
	return y<m-1 && !a[x][y+1];
}

bool amel(int x,int y)
{
	if(x>=n) return true;
	if(y>=m) return amel(x+1,0);
	if(a[x][y]) return amel(x,y+1);
	if(chk(x,y,1))
	{
		for(int i=5; i--; )
			a[x+A[i][0]][y+A[i][1]]=1;
		a[x][y]=1;
		return amel(x,y+1);
	}
	if(chk(x,y,0))
	{
		a[x][y]=a[x][y+1]=2;
		return amel(x,y+2);
	}
	return false;
}

void Solve()
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			char c;
			cin>>c;
			if(c=='.') a[i][j]=-1;
		}
	if(!amel(0,0)) cout<<-1;
	else
	{
		for(int i=0; i<n; i++,cout<<'\n')
			for(int j=0; j<m; j++)
				cout<<(~a[i][j] ? (char)('A'-1+a[i][j]) : '.');
	}
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
