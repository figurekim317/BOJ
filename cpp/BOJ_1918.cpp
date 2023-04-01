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
vector<string> b;
string a;

string amel(int p,int q)
{
	vector<string> tmp;
	for(int i=p; i<=q; i++)
	{
		if(b[i]=="*" || b[i]=="/")
		{
			assert(!tmp.empty());
			auto t=tmp.back()+b[i+1]+b[i];
			tmp.pop_back(); tmp.pb(t); i++;
		}
		else tmp.pb(b[i]);
	}
	string ret=tmp.front();
	for(int i=1; i<tmp.size(); i+=2)
		ret+=tmp[i+1]+tmp[i];
	return ret;
}

void Solve()
{
	cin>>a;
	for(auto &i: a) b.pb(string(1,i));
	stack<int> s;
	for(int i=0; i<b.size(); i++)
	{
		if(b[i]=="(") s.push(i);
		else if(b[i]==")")
		{
			auto t=amel(s.top()+1, i-1);
			b.erase(b.begin()+s.top(), b.begin()+i+1);
			b.insert(b.begin()+s.top(), t);
			i=s.top(); s.pop();
		}
	}
	cout<< amel(0,b.size()-1);
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
