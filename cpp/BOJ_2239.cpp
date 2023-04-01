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

int n,m,a[15][15];

void chk(vi &p, int x,int y)
{
	bool tmp[10]={};
	for(int i=9; i--;) tmp[a[i][y]]=tmp[a[x][i]]=true;
	int ii=x/3*3,jj=y/3*3;
	for(int i=ii; i<ii+3; i++)
		for(int j=jj; j<jj+3; j++) tmp[a[i][j]]=true;
	p.clear();
	for(int i=1;i<=9;i++) if(!tmp[i]) p.pb(i);
}

bool amel(int p,int q)
{
	if(q>=9) return amel(p+1,0);
	if(p>=9) return true;
	if(a[p][q]) return amel(p,q+1);
	vi tmp;
	chk(tmp,p,q);
	for(auto &i: tmp)
	{
		a[p][q]=i;
		if(amel(p,q+1)) return true;
	}
	a[p][q]=0;
	return false;
}

void Solve()
{
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			char c; cin>>c;
			a[i][j]=c-'0';
		}
	assert(amel(0,0));
	for(int i=0;i<9;i++,cout<<'\n')
		for(int j=0;j<9;j++) cout<<a[i][j];
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
