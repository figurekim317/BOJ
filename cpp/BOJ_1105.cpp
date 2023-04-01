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

ll n,m,ans,r;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(r=1;r<=m;r*=10);
    for(r/=10;r;r/=10)
    {
        int p=(n/r)%10,q=(m/r)%10;
        if(p==q) ans+=p==8;
        else {cout<<ans; return 0;}
    }
    cout<<ans;
    return 0;
}
