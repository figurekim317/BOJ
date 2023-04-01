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

int n,m,c[15];
vi a;

void Solve()
{
	cin>>n>>m;
	a.resize(n);
	memset(c,0,sizeof(c));
	for(auto &i: a) cin>>i, c[i]++;
	queue<int> b;
	for(int i = 0; i<n; i++) b.push(i);
	for(int i = 1; ; )
	{
		auto t = b.front(); b.pop();
		bool fl = true;
		for(int j = a[t]+1; j<10; j++)
			fl &= !c[j];
		if(fl)
		{
			if(t==m)
			{
				cout<<i<<'\n';
				return;
			}
			c[a[t]]--;
			i++;
		}
		else b.push(t);
	}
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
