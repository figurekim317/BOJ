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

int n,m,cnt,ans;

int main()
{
 //   freopen("input.txt","r",stdin);
    cin>>n>>m;
    ans=n;
    for(int i=0;n>>i;i++) cnt+=1&(n>>i);
    if(cnt<=m) {printf("0"); return 0;}
    for(int i=0;n>>i;i++)
    {
        if(1&(n>>i)) cnt--,n^=1<<i;
        else if(cnt<m)
        {
            n^=1<<i;
            cout<<n-ans;
            return 0;
        }
    }
    for(n=1;n<ans;n<<=1);
    cout<<n-ans;
    return 0;
}
