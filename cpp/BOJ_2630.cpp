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

int n,m,a[130][130];

pii amel(int x, int y, int b)
{
	if(b == 1)
		return a[x][y] ? mp(0, 1) : mp(1, 0);
	pii p,q,r,s;
	b>>=1;
	p = amel(x, y, b);
	q = amel(x + b, y, b);
	r = amel(x, y + b, b);
	s = amel(x + b, y + b, b);
	if(!(p.ff|q.ff|r.ff|s.ff)) return mp(0, 1);
	if(!(p.ss|q.ss|r.ss|s.ss)) return mp(1, 0);
	return mp(p.ff+q.ff+r.ff+s.ff, p.ss+q.ss+r.ss+s.ss);
}

void Solve()
{
	cin>>n;
	for(int i = n; i--; )
		for(int j = n; j--; ) cin>>a[i][j];
	auto t = amel(0, 0, n);
	cout<<t.ff<<'\n'<<t.ss;
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
