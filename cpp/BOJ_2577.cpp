#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 1000000

ll n,m,k;
int a[10];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld %lld",&n,&m,&k);
    for(n*=m*k;n;n/=10) a[n%10]++;
    for(int i=0;i<10;i++) printf("%d\n",a[i]);
    return 0;
}
