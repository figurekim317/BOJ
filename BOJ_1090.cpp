#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n;
pii a[55],b[55];
ll ans,cnt;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=n;i--;) cin>>a[i].ff>>a[i].ss;
    for(int i=1;i<=n;i++)
    {
        ans=LLONG_MAX;
        for(int j=n;j--;)
            for(int k=n;k--;)
            {
                for(int l=n;l--;)
                    b[l]={abs(a[l].ff-a[j].ff)+abs(a[l].ss-a[k].ss),l};
                sort(b,b+n);
                cnt=0;
                for(int l=i;l--;) cnt+=b[l].ff;
                ans=min(ans,cnt);
            }
        printf("%lld ",ans);
    }
    return 0;
}