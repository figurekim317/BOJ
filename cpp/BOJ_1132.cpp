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

int n,b[10];
ll a[10];

void Solve()
{
    cin>>n;
    for(string i; n--; )
    {
        cin>>i;
        b[i[0]-'A']=1;
        for(ll j=i.size(),k=1;j--;k*=10)
            a[i[j]-'A']+=k;
    }
    vector<pair<ll, int> > c;
    for(int i=10;i--;) c.pb({a[i],i});
    sort(c.begin(), c.end());
    for(auto i=c.begin(); i!=c.end(); ++i) if(!b[i->ss]) {c.erase(i); break;}
    ll ans=0;
    for(int i=1;i<10;i++) ans+=c[i-1].ff * i;
    cout<<ans;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
