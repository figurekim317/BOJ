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

int n,m,ans=INT_MAX;
vi a(5);

void Solve()
{
    for(auto &i:a) cin>>i;
    for(int i=5;i--;)
        for(int j=i;j--;)
        {
            int t=a[i]*a[j]/__gcd(a[i],a[j]);
            for(int k=j;k--;)
                ans=min(ans, a[k]*t/__gcd(a[k],t));
        }
    cout<<ans;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
