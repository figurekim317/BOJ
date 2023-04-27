

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

int n,a[55][55],ans;
list<int> fr[55];

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    char c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>c,a[i][j]=c=='Y';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(a[i][j]) fr[i].pb(j);
    for(int i=1;i<=n;i++)
    {
        set<int> b;
        for(int j=1;j<=n;j++)
            if(a[i][j])
            {
                b.insert(j);
                for(auto k:fr[j]) b.insert(k);
            }
        b.erase(i);
        ans=max(ans,(int)b.size());
    }
    cout<<ans;
    return 0;
}
