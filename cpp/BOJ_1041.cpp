#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 1000000007

ll n,a[10],b[15],c[10],blen,clen;

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%lld",&n);
    for(int i=0;i<6;i++) scanf("%lld",a+i);
    if(n==1) {sort(a,a+6); printf("%lld",a[0]+a[1]+a[2]+a[3]+a[4]); return 0;}
    b[blen++]=a[0]+a[1]; b[blen++]=a[0]+a[2]; b[blen++]=a[0]+a[3];
    b[blen++]=a[0]+a[4]; b[blen++]=a[1]+a[2]; b[blen++]=a[1]+a[3];
    b[blen++]=a[1]+a[5]; b[blen++]=a[2]+a[4]; b[blen++]=a[2]+a[5];
    b[blen++]=a[3]+a[4]; b[blen++]=a[3]+a[5]; b[blen++]=a[4]+a[5];
    c[clen++]=a[0]+a[1]+a[2]; c[clen++]=a[0]+a[1]+a[3];
    c[clen++]=a[0]+a[3]+a[4]; c[clen++]=a[0]+a[4]+a[2];
    c[clen++]=a[5]+a[1]+a[2]; c[clen++]=a[5]+a[1]+a[3];
    c[clen++]=a[5]+a[3]+a[4]; c[clen++]=a[5]+a[4]+a[2];
    printf("%lld",((n-2)*(n-1)*4ll+(n-2)*(n-2))**min_element(a,a+6)+
                ((n-2)*4ll+(n-1)*4ll)**min_element(b,b+blen)+
                4ll**min_element(c,c+clen));
    return 0;
}
