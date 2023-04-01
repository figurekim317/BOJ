#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 998244353
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,a[55],dp[55][55];
vector<int> b[2];

void Solve()
{
    cin>>n;
    for(int i=n;i--;) cin>>a[i];
    if(n==1) {cout<<a[0]; return;}
    sort(a,a+n);
    reverse(a,a+n);
    dp[1][0]=a[0]-a[1];
    for(int i=2;i<n;i++)
    {
        dp[i][i-1]=INT_MAX;
        for(int j=0;j<i-1;j++)
            dp[i][j]=max(dp[i-1][j],a[i-1]-a[i]),
            dp[i][i-1]=min(dp[i][i-1],max(dp[i-1][j],a[j]-a[i]));
    }
    for(int i=0;i<n-1;i++) dp[n-1][i]=max(dp[n-1][i],a[i]-a[n-1]);
    int ans=*min_element(dp[n-1],dp[n-1]+n-1);
    for(int i=n-2,j=0;i;j^=1)
    {
        int r;
        if(j)
        {
            for(int k=0;k<i;k++) if(ans>=dp[i][k]&&ans>=a[k]-a[i+1]) r=k;
        }
        else
        {
            for(int k=i;k--;) if(ans>=dp[i][k]&&ans>=a[k]-a[i+1]) r=k;
        }
        for(int k=i;k>r;k--) b[j].pb(a[k]);
        i=r;
    }
    reverse(b[1].begin(),b[1].end());
    cout<<a[n-1]<<' ';
    for(auto i:b[0]) cout<<i<<' ';
    cout<<a[0]<<' ';
    for(auto i:b[1]) cout<<i<<' ';
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}

