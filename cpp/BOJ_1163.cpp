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
string a;
string dp[120][120];

string grthan(string p, string q)
{
	assert(p.size()==q.size());
	if(p.empty()) return p;
	if(p.size()==1)
	{
		if(q.front() == '?')
			return p.front() == '9' ? string() : string(1, p.front()+1);
		return p.front() >= q.front() ? string() : q;
	}
	if(q.front() != '?')
	{
		if(q.front() < p.front()) return string();
		if(q.front() > p.front())
		{
			for(int i = 1; i< q.size(); i++)
				if(q[i] == '?') q[i]='0';
			return q;
		}
		string ret = grthan(p.substr(1), q.substr(1));
		return ret.empty() ? ret : (q.substr(0, 1) + ret);
	}
	string ret = grthan(p.substr(1), q.substr(1));
	if(!ret.empty()) return p.substr(0,1) + ret;
	if(p.front() == '9') return string();
	q.front() = p.front() + 1;
	for(int i = 1; i< q.size(); i++)
		if(q[i] == '?') q[i]='0';
	return q;
}

string nine(int p)
{
	string ret("0");
	for(p--; p--; ) ret+="9";
	return ret;
}

bool amel(int pos, string p)
{
	for(int i = n+3; i--; )
		for(int j = n+3; j--; ) dp[i][j].clear();

	dp[pos-1][p.size()] = p;

	for(int i = pos + p.size(); i<n; i++)
		if(a[i] == ',' || a[i] =='?')
		{
			for(int j = 1; a[i-j] != ',' && j<=i-pos; j++)
			{
				bool fl=false;
				for(int k = 1; k<j; k++)
					if(!dp[i-j-1][k].empty()) {fl=true; break;}
				if(fl)
					dp[i][j] = grthan(nine(j), a.substr(i-j, j));
				else if(!dp[i-j-1][j].empty())
					dp[i][j] = grthan(dp[i-j-1][j], a.substr(i-j,j));
			}
		}
	for(int i = 1; i<n; i++)
		if(!dp[n-1][i].empty()) return true;
	return false;
}

bool gr(string p, string q)
{
	for(int i = 0; i<min(p.size(),q.size()); i++)
		if(p[i] != q[i]) return p[i] < q[i];
	return p.size() < q.size();
}

void Solve()
{
	cin>>a;
	a = "0," + a + ",";
	n=a.size();
	if(!amel(2, "0")) {cout<<-1; return;}
	for(int i = 2; i<n; i++)
	{
		vector<string> tmp;
		for(int j = 1; i+j<n; j++)
			if(!dp[i+j][j].empty()) tmp.pb(dp[i+j][j]);
		sort(tmp.begin(),tmp.end(),gr);
		for(auto &j: tmp)
			if(amel(i+j.size()+1, j))
			{
				a.replace(i, j.size(), j);
				a[i+j.size()] = ',';
				i+=j.size();
				break;
			}
	}
	cout<<a.substr(2, n-3);
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
