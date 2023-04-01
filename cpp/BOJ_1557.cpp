#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 998244353
#define N 100000
#define M 3010

int n,m;
bool a[50000]={1,1};
ll pr[5000];

ll amel(ll p,ll w,int idx)
{
    ll ret=0;
    for(int i=idx;i<m;i++)
    {
        if(w*pr[i]>(ll)sqrt(p)+2) break;
        ret+=p/(w*pr[i]*w*pr[i])-amel(p,w*pr[i],i+1);
    }
    return ret;
}

void Solve()
{
    cin>> n;

    pr[m++]=2;
    for(ll i=3;i*i<2000000000;i+=2)
        if(!a[i])
        {
            for(ll j=i*3;j*j<2000000000;j+=i<<1)
                a[j]=1;
            pr[m++]=i;
        }

    ll lf=n,rg=n<<1;
    while(lf<rg)
    {
        ll mid=lf+rg>>1;
        if(mid - amel(mid,1,0) >= (ll)n) rg=mid;
        else lf=mid+1;
    }
    cout<< lf;
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}

