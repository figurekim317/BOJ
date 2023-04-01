#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m;
vi a,sum;
bool dp[35][35][1010];

void Solve()
{
    cin>>m>>n;
    a.resize(n);
    sum.resize(n+1);
    for(auto &i:a) cin>>i;
    sort(a.begin(), a.end());
    sum[0]=0;
    for(int i=0;i<n;i++) sum[i+1]=sum[i]+a[i];
    dp[n][0][0]=true;
    for(int i=n; i--; )
        for(int j=n-i+1; j--; )
            for(int k=m+1; k--; )
            {
                dp[i][j][k] = dp[i+1][j][k];
                if(j && k>=a[i]) dp[i][j][k] |= dp[i+1][j-1][k-a[i]];
            }
    for(int i=0;i<n;i++)
        for(int j=0; j<=i; j++)
            for(int k = max(0, m + 1 - (sum[j] + a[j] * (i+1))); k<= m-sum[j]; k++)
                if(dp[j+1][i-j][k]) {cout<<i; return;}
    cout<<n;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
