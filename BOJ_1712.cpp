#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1000010
#define MOD 1000000007

int n,m,k;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    if(m>=k) {printf("-1"); return 0;}
    printf("%d",n/(k-m)+1);
    return 0;
}
