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

int n,m,a[100][100];

string amel(int x,int y,int p)
{
	if(p==1) return string(1,a[x][y]+'0');
	p>>=1;
	auto a1=amel(x,y,p), a2=amel(x,y+p,p), a3=amel(x+p,y,p), a4=amel(x+p,y+p,p);
	if(a1.size()==1 && a1==a2 && a2==a3 && a3==a4) return a1;
	return '('+a1+a2+a3+a4+')';
}

void Solve()
{
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		string b;
		cin>>b;
		for(int j=0; j<n; j++) a[i][j]=b[j]-'0';
	}
	cout<<amel(0,0,n);
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
