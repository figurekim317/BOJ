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

int n,m,a[12],ans;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0,j;i<m;i++) scanf("%d",&j),a[j]=1;
    ans=abs(n-100);
    for(int i=n+ans+10;i--;)
    {
        int cnt=0;
        for(int j=i;j;j/=10,cnt++) if(a[j%10]) {cnt=-1; break;}
        if(!i) cnt=a[0]?-1:1;
        if(~cnt) ans=min(ans,abs(i-n)+cnt);
    }
    cout<<ans;
    return 0;
}
