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

int n,m,ten[55]={1},a[20],b[20];
ll ans[(1<<15)+10][110]={1};
string c[20];
list<int> d[20];

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>c[i];
    cin>>m;
    for(int i=1;i<51;i++) ten[i]=ten[i-1]*10%m;
    for(int i=0;i<n;i++) b[i]=ten[c[i].length()];
    for(int i=0;i<n;i++)
        for(int j=c[i].length(),k=0;j--;k++)
            a[i]=(a[i]+ten[k]*(c[i][j]-'0'))%m;

    for(int i=1,cnt;i<1<<n;i++)
    {
        cnt=0;
        for(int j=i;j;j>>=1) cnt+=j&1;
        d[cnt].pb(i);
    }
    for(int ii=1;ii<=n;ii++)
        for(auto i:d[ii])
            for(int j=0;i>>j;j++)
                if(i>>j&1)
                    for(int k=0;k<m;k++)
                        ans[i][(k*b[j]+a[j])%m]+=ans[i^1<<j][k];
    ll p=ans[(1<<n)-1][0],q=1;
//    cout<<p<<'\n';
    if(!p) { printf("0/1"); return 0; }
    for(ll i=2;i<=n;i++) q*=i;
    ll tmp=__gcd(p,q);
    printf("%lld/%lld",p/tmp,q/tmp);
    return 0;
}