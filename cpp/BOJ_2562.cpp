#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1000010
#define MOD 1000000007

int n,m,k;

int main(){
  //  freopen("input.txt","r",stdin);
    for(int i=1;~scanf("%d",&n);i++)
        if(m<n) m=n,k=i;
    printf("%d\n%d",m,k);
    return 0;
}
