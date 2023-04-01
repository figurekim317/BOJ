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

int n,m,a[55];

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=n;i--;)
    {
        int cnt=0,t;
        for(int j=m,k;j--;)
        {
            scanf("%d",&k);
            if(k) cnt++,t=j;
        }
        if(!cnt) n--;
        else if(cnt==1) a[t]=1;
    }
    for(int i=m;i--;) n-=a[i];
    cout<<max(0,n-1);
    return 0;
}