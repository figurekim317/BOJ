#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define MOD 1000000000

int n,m,ans,p;

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d",&p);
    while(~scanf("%d",&n)) m=max(m,n),ans+=n;
    printf("%.3f",(float)ans*100/p/m);
    return 0;
}
