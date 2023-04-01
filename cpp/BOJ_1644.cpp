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

int n,m;
bitset<4'000'010> a;
vi p;
vl b;

void Solve()
{
	cin>>n;
	p.pb(2);
	for(int i=3; i<=n; i+=2)
		if(!a.test(i))
		{
			p.pb(i);
			for(int j=i*3; j<=n; j+=i<<1) a.set(j);
		}
	b.resize(p.size()+1);
	b.front()=0;
	for(int i=0; i<p.size(); i++) b[i+1]=b[i]+p[i];
	for(int i=0; i<b.size(); i++)
		m+=binary_search(b.begin()+i+1, b.end(), b[i]+n);
	cout<<m;
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
