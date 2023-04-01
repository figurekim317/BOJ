#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 95
#define M 1010
#define MOD 15746

int n,m;
ll a[N][2];

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    a[1][1]=1;
    for(int i=2;i<=n;i++)
        a[i][1]=a[i-1][0],
        a[i][0]=a[i-1][0]+a[i-1][1];
    printf("%lld",a[n][0]+a[n][1]);
    return 0;
}
