#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

ll n,p,x,q,y;

void Solve()
{
    while(~scanf("%lld %lld %lld %lld %lld", &n,&p,&x,&q,&y))
    {
        ll ans=n*10;

        ans=min(ans, (n/p+1)*x);
        ans=min(ans, (n/q+1)*y);

        for(ll i = n/p, r = (n/p) * x, t = n%p; i>=0 && i >= n/p - q; i--, r-=x, t+=p)
        {
            ans=min(ans, r + t*10);
            ll tmp = t / q;
            ans=min(ans, r + tmp*y + (t%q)*10);
            ans=min(ans, r + (tmp+1)*y);
        }

        for(ll i = n/q, r = (n/q) * y, t = n%q; i>=0 && i >= n/q - p; i--, r-=y, t+=q)
        {
            ans=min(ans, r + t*10);
            ll tmp = t / p;
            ans=min(ans, r + tmp*x + (t%p)*10);
            ans=min(ans, r + (tmp+1)*x);
        }

        cout<<ans<<'\n';
    }
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
