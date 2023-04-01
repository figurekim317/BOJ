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

int n,m,a[110][110],vis[110],ans[110];

void Solve()
{
	cin>>n>>m;
	for(int i,j; m--; ) cin>>i>>j, a[i-1][j-1]=a[j-1][i-1]=1;
	for(int i=n; i--; )
	{
		memset(vis,-1,sizeof(vis));
		queue<int> bfs;
		bfs.push(i); vis[i]=0;
		while(!bfs.empty())
		{
			auto t=bfs.front(); bfs.pop();
			for(int j=n; j--; )
				if(a[t][j]&&!~vis[j])
					vis[j]=vis[t]+1, bfs.push(j);
		}
		for(int j=n; j--; ) ans[i]+=vis[j];
	}
	cout<<min_element(ans,ans+n)-ans+1;
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
