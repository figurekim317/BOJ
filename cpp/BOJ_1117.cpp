#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

ll n,m,f,c,x1,y11,x2,y2,ans;

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc;
    cin>>n>>m>>f>>c>>x1>>y11>>x2>>y2;
    if(x2<=min(f,n-f)) ans=(x2-x1)*(y2-y11)*(c+1)*2;
    else if(min(f,n-f)<=x1) ans=(x2-x1)*(y2-y11)*(c+1);
    else ans=((min(f,n-f)-x1)*2+x2-min(f,n-f))*(y2-y11)*(c+1);
    printf("%lld",n*m-ans);
    return 0;
}
