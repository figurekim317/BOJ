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
set<string> a;
vector<string> ans;

void Solve()
{
	cin>>n>>m;
	for(string b; n--;)
		cin>>b, a.insert(b);
	for(string b; m--; )
	{
		cin>>b;
		if(a.find(b) != a.end())
			ans.pb(b);
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<'\n';
	for(auto &i: ans) cout<<i<<'\n';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"if( b == #"<<i<<'\n',
	Solve();
	return 0;
}
