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

int n,a[55],vis[55],ans;

int main(){
 //   freopen("input.txt","r",stdin);
//    int tc; cin>>tc;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=n;i--;)
        if(!vis[i])
        {
            ans++;
            for(int j=i;!vis[j];j=a[j]) vis[j]=1;
        }
    if(ans==1) cout<<'0';
    else cout<<ans;
    return 0;
}
