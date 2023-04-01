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

int n,m;
pair<int,ll> dp[35][3];
string a[6];

void Solve()
{
    cin>>n;
    for(auto &i:a) cin>>i;
    for(int i=3;i--;)
    {
        for(auto &j:a)
            if(j[0]-'A'==i)
            {
                dp[1][i]=mp(j[1]-'A',1ll);
                break;
            }
    }
    for(int i=2;i<=n;i++)
        for(int j=3;j--;)
        {
            for(int t=j,k=j;;)
            {
                dp[i][j].ss+=dp[i-1][k].ss;
                k=dp[i-1][k].ff;
                if(k==t)
                {
                    dp[i][j].ff=t;
                    break;
                }
                t=3-t-k;
                dp[i][j].ss++;
            }
        }
    cout<<dp[n][0].ss;
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
