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
#define MOD 1'000'000'009

int n,m,a[30];

void Solve()
{
    cin>>n;
    for(string i;n--;)
        cin>>i, a[i[0]-'a']++;
    string ans;
    for(int i=0;i<26;i++) if(a[i]>4) ans.pb(i+'a');
    if(ans.empty()) cout<<"PREDAJA";
    else cout<<ans;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){Init(01);
//    int tc; cin>>tc; for(int i=1;i<=tc;i++)
//    cout<<"Case #"<<i<<'\n',
    Solve();
    return 0;
}
