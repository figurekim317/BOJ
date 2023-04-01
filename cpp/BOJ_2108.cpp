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

int n,m,b[8010];
vi a;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	sort(a.begin(), a.end());
	for(auto &i: a) m+=i, b[i+4000]++;
	cout.precision(0);
	cout<<fixed<<(double)m/n<<'\n';
	cout<<a[n>>1]<<'\n';
	auto t = max_element(b, b+8005);
	bool fl = false;
	for(int i = 0; i < 8005; i++)
		if(b[i] == *t)
		{
			if(fl)
			{
				cout<<i-4000<<'\n';
				fl=false;
				break;
			}
			else fl=true;
		}
	if(fl) cout<<(t-b)-4000<<'\n';
	cout<<(ll)a.back() - a.front();
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
