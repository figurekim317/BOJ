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

int n,m,a[20][20],ans[(1<<16)+5],r,w,dap=INT_MAX;
char cc;
list<int> b[20];

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",a[i]+j);
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&cc);
        if(cc=='Y') w++,r|=1<<i;
    }
    cin>>m;
    if(m<=w) {printf("0"); return 0;}
    if(!w) {printf("-1"); return 0;}
    memset(ans,1,sizeof(ans)); ans[r]=0;
    for(int i=1<<n;i--;)
    {
        int cnt=0;
        for(int j=0;i>>j;j++) if(i>>j&1) cnt++;
        b[cnt].pb(i);
    }
    for(int i=w;i<=m;i++)
        for(auto j:b[i])
            for(int k=0;j>>k;k++)
                if(j>>k&1)
                    for(int l=0;l<n;l++)
                        if(!(j>>l&1)) ans[j|1<<l]=min(ans[j|1<<l],ans[j]+a[k][l]);
    for(auto i:b[m]) dap=min(dap,ans[i]);
    printf("%d",dap);
    return 0;
}
