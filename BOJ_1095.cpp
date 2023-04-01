#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int k;
ll n,m,a[100010];
list<int> b;

bool chk(int p)
{
    for(auto i:b)
    {
        if(p==1) return 1;
        int cnt=0;
        while(p%i==0) p/=i,cnt++;
        if(a[i]<cnt) return 0;
    }
    return 1;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m>>k;
    b.pb(2);
    for(int i=3;i<=k;i+=2)
        if(!a[i])
        {
            b.pb(i);
            for(int j=i*3;j<=k;j+=i<<1) a[j]=-1;
        }
    for(auto i:b)
        for(ll j=i;j<=n+m;j*=(ll)i)
            a[i]+=(n+m)/j-n/j-m/j;
    for(int i=k;i;i--)
        if(chk(i)) {printf("%d",i); break;}
    return 0;
}