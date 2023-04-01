#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 1000000

int n,m,a[N],b[N]={1,1,1},ans;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n*(n-1)*(n-2)/6;i++,next_permutation(b,b+n))
    {
        int tmp=0;
        for(int j=0;j<n;j++)
            if(b[j]) tmp+=a[j];
        if(tmp<=m) ans=max(ans,tmp);
    }
    printf("%d",ans);
    return 0;
}
