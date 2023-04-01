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

int n;
vi a;
vector<double> ans;
vector<vi> b;

double amel(int p,int q,int r)
{
    p=a[p]; q=a[q]; r=a[r];
    double t=(double)(p+q+r)/2;
    return sqrt(t*(t-p)*(t-q)*(t-r));
}

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i;
    ans.resize(1<<n);
    b.resize(n+1);
    for(int i=1<<n;i--;)
    {
        int cnt=0;
        for(int j=0;i>>j;j++) cnt+=(i>>j)&1;
        b[cnt].pb(i);
    }
    b[0].clear();
    for(auto i:b)
        for(auto j:i)
        {
            int k=n;
            while(!((j>>k)&1)) k--;
            ans[j]=ans[j^(1<<k)];
            for(int p=k; p--; )
                for(int q=p; q--; )
                    if((j>>p)&(j>>q)&1) ans[j]=max(ans[j], ans[j^(1<<k)^(1<<p)^(1<<q)] + amel(k,p,q));
        }
    printf("%.9f", ans.back());
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
