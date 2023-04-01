#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

pii a[3];
double b[3];

int main()
{
    //freopen("input.txt","r",stdin);
    for(int i=3;i--;) cin>>a[i].ff>>a[i].ss;
    if((a[2].ss-a[1].ss)*(a[1].ff-a[0].ff)==(a[2].ff-a[1].ff)*(a[1].ss-a[0].ss)) {printf("-1"); return 0;}
    for(int i=3;i--;)
        b[i]=hypot((double)a[i].ff-a[(i+1)%3].ff,(double)a[i].ss-a[(i+1)%3].ss);
    sort(b,b+3);
    printf("%.9f",(b[2]-b[0])*2);
    return 0;
}
