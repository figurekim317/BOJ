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

int n,m,a[55];

int main()
{
 //   freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    n++;
    cin>>m;
    sort(a,a+n);
    int t=lower_bound(a,a+n,m)-a;
    if(a[t]==m) cout<<"0";
    else cout<<(m-a[t-1])*(a[t]-m)-1;
    return 0;
}
