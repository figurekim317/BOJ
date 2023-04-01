#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m;
ll a[110]={1,1},r=1000000,c[110][110]={1};

void Solve()
{
    cin>>n;
    if(n==1) {cout<<1; return;}
    for(int i=1;i<n;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%r;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1; j<=i; j++)
        {
            a[i] += c[i-1][j-1] * a[j-1] * a[i-j];
            a[i] %= r;
        }
        a[i]>>=1;
    }
    cout<<(a[n]<<1)%r;
}

int main(){
//    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
