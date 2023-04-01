#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 61
#define MOD 10007

ll n,m;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(ll i=(ll)sqrt((double)(n<<1));;i++)
        if(i*(i+1)>=n<<1)
        {
            ll p=(i*(i+1)>>1)-n;
            printf("%lld/%lld",i&1ll?p+1:i-p,i&1ll?i-p:p+1);
            return 0;
        }
    return 0;
}
