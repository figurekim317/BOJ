#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll a,b,c;

ll amel(ll p,ll q)
{
    if(!q) return 1;
    return q&1ll?p*amel(p*p%c,q>>1)%c:amel(p*p%c,q>>1)%c;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld",amel(a,b));
    return 0;
}
