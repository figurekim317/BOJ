#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 200010
#define M 3010

int n,m,a[55],c;
ll ans[2][55][50010],dap;

int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    sort(a+1,a+n+1);
    ans[0][0][0]=1;
    for(int i=1;i<n;i++)
    {
        ans[i&1][0][0]=1;
        for(int j=1;j<=i;j++)
        {
            for(int k=0;k<=a[n]+1;k++) ans[i&1][j][k]=ans[i-1&1][j][k];
            for(int k=0;k<=a[n]+1;k++)
                ans[i&1][j][k]+=ans[i-1&1][j-1][max(0,k-a[i])];
        }
        dap+=ans[i&1][m-1][a[i+1]+1];
    }
    cout<<dap;

    /*
}//*/
    return 0;
}
