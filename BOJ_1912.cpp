#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define MOD 1000000000

int n,m,ans=INT_MIN;

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(~scanf("%d",&n))
    {
        m+=n;
        ans=max(ans,m);
        if(m<0) m=0;
    }
    printf("%d",ans);
    return 0;
}
