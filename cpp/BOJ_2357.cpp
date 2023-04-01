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

struct minsegtree {
	int a[300'010];
	int siz;

	void init(int p, vector<int> &src) {
		// Do any initialize on a[] if not using sum;
		memset(a,0x77,sizeof(a));
		for(siz = 1; siz < p; siz <<= 1) ;
		for(int i = p; i--; ) a[i | siz] = src[i];
		for(int i = siz; i--; ) a[i] = min(a[i << 1], a[i << 1 | 1]); // +
	}

	// get a[lf] + a[lf + 1] + ... + a[rg]
	int sum(int lf, int rg) {
		int ret = INT_MAX;							// Init
		lf |= siz; rg |= siz;
		while(lf < rg) {
			if(lf & 1) ret =min(ret, a[lf++]); 			// +
			else if(~rg & 1) ret =min(ret, a[rg--]);	// +
			else lf >>= 1, rg >>= 1;
		}
		return min(ret, a[lf]); 					// +
	}
}a;

struct maxsegtree {
	int a[300'010];
	int siz;

	void init(int p, vector<int> &src) {
		// Do any initialize on a[] if not using sum;
		for(siz = 1; siz < p; siz <<= 1) ;
		for(int i = p; i--; ) a[i | siz] = src[i];
		for(int i = siz; i--; ) a[i] = max(a[i << 1], a[i << 1 | 1]); // +
	}

	// get a[lf] + a[lf + 1] + ... + a[rg]
	int sum(int lf, int rg) {
		int ret = 0;							// Init
		lf |= siz; rg |= siz;
		while(lf < rg) {
			if(lf & 1) ret =max(ret, a[lf++]); 			// +
			else if(~rg & 1) ret =max(ret, a[rg--]);	// +
			else lf >>= 1, rg >>= 1;
		}
		return max(ret, a[lf]); 					// +
	}
}b;

void Solve()
{
	cin>>n>>m;
	vi p;
	for(int i=n,j;i--;) cin>>j,p.pb(j);
	a.init(n,p); b.init(n,p);
	for(int i,j;m--;)
	{
		cin>>i>>j;
		cout<<a.sum(i-1,j-1)<<' '<<b.sum(i-1,j-1)<<'\n';
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
