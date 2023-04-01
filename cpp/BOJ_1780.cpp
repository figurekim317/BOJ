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

int n,m,a[2200][2200];

struct aa
{
	int x,y,z;
	aa(){}
	aa(int mx,int my,int mz){x=mx;y=my;z=mz;}
};

aa amel(int x, int y, int b)
{
	if(b == 1)
		switch(a[x][y])
		{
			case -1: return aa(1,0,0);
			case 0: return aa(0,1,0);
			case 1: return aa(0,0,1);
		}
	bool p=true,q=true,r=true;
	aa res(0,0,0);
	for(int i = x; i < x+b; i+=b/3)
		for(int j = y; j < y+b; j+=b/3)
		{
			auto t = amel(i, j, b/3);
			p &= !(t.y|t.z);
			q &= !(t.z|t.x);
			r &= !(t.x|t.y);
			res.x+=t.x; res.y+=t.y; res.z+=t.z;
		}
	if(p) return aa(1,0,0);
	if(q) return aa(0,1,0);
	if(r) return aa(0,0,1);
	return res;
}

void Solve()
{
	cin>>n;
	for(int i = n; i--; )
		for(int j = n; j--; ) cin>>a[i][j];
	auto t = amel(0, 0, n);
	cout<<t.x<<'\n'<<t.y<<'\n'<<t.z;
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
