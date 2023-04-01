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

int n,m,a[1010][1010],b[1010];
vi ed[1010];

bool dfs(int p)
{
    for(auto &i:ed[p])
    {
        if(b[i]==b[p]) return false;
        if(!~b[i])
        {
            b[i]=!b[p];
            if(!dfs(i)) return false;
        }
    }
    return true;
}

void Solve()
{
    cin>>n;
    for(int i,j;;)
    {
        cin>>i>>j;
        if(!~i) break;
        a[i][j]=a[j][i]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j&&!a[i][j]) ed[i].pb(j);
    memset(b,-1,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        if(!~b[i])
        {
            b[i]=0;
            if(!dfs(i)) {cout<<-1; return;}
        }
    }
    cout<<"1\n";
    for(int i=1;i<=n;i++) if(!b[i]) cout<<i<<' ';
    cout<<"-1\n";
    for(int i=1;i<=n;i++) if(b[i]) cout<<i<<' ';
    cout<<-1;
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
