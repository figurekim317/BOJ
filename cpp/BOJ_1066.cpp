#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 200010
#define M 100010

int n,m;
ll ans[1010][10][10][10];

int main()
{
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    if(m>n+1>>1) {printf("0"); return 0;}
    for(int i=1;i<10;i++) ans[1][1][i][9]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=min(9,i+1>>1);j++)
        {
            for(int k=1;k<10;k++)
            {
                for(int l=0;l<9;l++)
                {
                    if(k+l<10)
                        ans[i][j][k+l][l]+=ans[i-1][j][k][l]+ans[i-1][j][k][9],
                        ans[i][j][k+l][l]%=MOD;
                    for(int f=k;f<10;f++)
                        if(f!=k+l)
                            ans[i][j][f][9]+=ans[i-1][j-1][k][l],
                            ans[i][j][f][9]%=MOD;
                }
            }
        }
    ll dap=0;
    for(int i=1;i<10;i++)
        for(int j=0;j<=9;j++) dap+=ans[n][m][i][j],dap%=MOD;
    cout<<dap;
    return 0;
}
