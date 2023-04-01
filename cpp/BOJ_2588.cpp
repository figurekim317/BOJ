#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 55
#define MOD 1000000007

int n,m;

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    printf("%d\n%d\n%d\n%d",n*(m%10),n*(m/10%10),n*(m/100),n*m);
    return 0;
}
