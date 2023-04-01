#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

int n,m,a[55][55],ans;

int main()
{
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%1d",a[i]+j);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=min(n-i,m-j);k;k--)
                if(a[i][j]==a[i][j+k]&&a[i][j]==a[i+k][j]&&a[i][j]==a[i+k][j+k]) ans=max(ans,k);
    ans++;
    cout<<ans*ans;
    return 0;
}
