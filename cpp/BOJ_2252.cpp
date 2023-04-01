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

int n,m,b[32'010];
vvi ed;
queue<int> a;

void Solve()
{
	cin>>n>>m;
	ed.resize(n+1);
	for(int i,j;m--;) cin>>i>>j,ed[i].pb(j),b[j]++;
	for(int i=1;i<=n;i++) if(!b[i]) a.push(i);
	while(!a.empty())
	{
		int t=a.front(); a.pop();
		cout<<t<<' ';
		for(auto &i: ed[t])
		{
			b[i]--;
			if(!b[i]) a.push(i);
		}
	}
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
