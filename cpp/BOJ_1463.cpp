#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1000010
#define MOD 1000000007

int n,m,a[N];

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d",&n);
    memset(a,1,sizeof(a)); a[n]=0;
    for(int i=n;i;i--)
    {
        if(!(i%3)) a[i/3]=min(a[i/3],a[i]+1);
        if(!(i&1)) a[i>>1]=min(a[i>>1],a[i]+1);
        a[i-1]=min(a[i-1],a[i]+1);
    }
    printf("%d",a[1]);
    return 0;
}
