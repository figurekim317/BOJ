#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int w,n,a[10010][110]={1};

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>w>>n;
    for(int i=1,p,q;i<=n;i++)
    {
        cin>>p>>q;
        for(int j=0;q>=0&&j<=w;q--,j+=p)
            for(int k=0;k<=w-j;k++) a[k+j][i]+=a[k][i-1];
    }
    cout<<a[w][n];
    return 0;
}