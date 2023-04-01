#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

ll n,m,ans,dap;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>m;

//    srand(time(NULL));
//    n=rand()%100000;
//    m=rand()%100000;
//    if(n>m) swap(n,m);

//    n=12154; m=31781;

    for(ll i=1;i<=m;i*=10)
    {
        int a=n/i%10,b=m/i%10;
        if(n/i/10==m/i/10)
        {
            if(a==b) ans+=(m%i-n%i+1)*a;
            else
            {
                ans+=i*(b*(b-1)-a*(a+1))>>1;
                ans+=(i-n%i)*a;
                ans+=(m%i+1)*b;
            }
        }
        else
        {
            ans+=i*(m/i/10-n/i/10-1)*45;
            ans+=i*(90-a*(a+1))>>1;
            ans+=i*b*(b-1)>>1;
            ans+=(i-n%i)*a+(m%i+1)*b;
        }
//        cout<<ans<<'\n';
    }
//    printf("-------\n");
//    for(ll i=1;i<=m;i*=10)
//    {
//        for(ll j=n;j<=m;j++)
//            dap+=(j/i)%10;
//        cout<<dap<<'\n';
//    }
//    if(dap!=ans) printf("n, m: %lld %lld\nans: %lld\nmy: ",n,m,dap);
    cout<<ans;
    return 0;
}