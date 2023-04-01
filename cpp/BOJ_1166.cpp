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
int a,b,c;
double ans;

int amel(int p,int pp,int q)
{
	if((double)q*pp/p>(double)n+5) return n+1;
	int lf=0,rg=n+5;
	while(lf<rg)
	{
		int md=lf+rg+1>>1;
		if((ll)p*md>(ll)q*pp) rg=md-1;
		else lf=md;
	}
	return lf;
}

bool chk(int p,int q)
{
	int x,y;
	switch(q)
	{
		case 1: x=amel(a,p,b),y=amel(a,p,c); break;
		case 2: x=amel(b,p,c),y=amel(b,p,a); break;
		case 3: x=amel(c,p,a),y=amel(c,p,b);
	}
	if(!x||!y) return false;
	if(x>n||y>n) return true;
	if((ll)x*y>(ll)n) return true;
	return (ll)n<=(ll)p*x*y;
}

void Solve()
{
	cin>>n>>a>>b>>c;
	for(int i=1;i<4;i++)
	{
		int lf=1,rg=n;
		if(!chk(n,i)) continue;
		while(lf<rg)
		{
			int md=lf+rg>>1;
			if(chk(md,i)) rg=md;
			else lf=md+1;
		}
		ans=max(ans,(double)(i==1?a:(i==2?b:c))/lf);
	}
	cout.precision(9);
	cout<<fixed<<ans;
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

