#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 310
#define MOD 1000000007

int n,m,a[N],ans[N][2];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    ans[1][0]=a[1]; ans[2][0]=a[2];
    for(int i=1;i<n;i++)
        ans[i+1][1]=max(ans[i+1][1],ans[i][0]+a[i+1]),
        ans[i+2][0]=max(ans[i+2][0],max(ans[i][0],ans[i][1])+a[i+2]);
    printf("%d",max(ans[n][0],ans[n][1]));
    return 0;
}
