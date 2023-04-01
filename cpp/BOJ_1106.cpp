#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

ll n,m,c[25],a[25],ans[1010];

int main(){
    freopen("input.txt","r",stdin);
    cin>>m>>n;
    for(int i=0;i<n;i++) scanf("%d %d",c+i,a+i);
    memset(ans,1,sizeof(ans)); ans[0]=0;
    for(int i=0;i<=m;i++)
        for(int j=0;j<n;j++)
            for(int k=i+1;k<=m;k++)
                ans[k]=min(ans[k],ans[i]+c[j]*((k-i-1)/a[j]+1));
    cout<<ans[m];
    return 0;
}
