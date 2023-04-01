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
#define M 3010

int n,m,a[110],ans[10010];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=n;i--;) scanf("%d",a+i);
    memset(ans,-1,sizeof(ans));
    ans[0]=0;
    for(int i=0;i<=m;i++)
        if(~ans[i])
            for(int j=n;j--;)
                if(i+a[j]<=m&&(!~ans[i+a[j]]||ans[i+a[j]]>ans[i]+1))
                    ans[i+a[j]]=ans[i]+1;
    cout<<ans[m];
    return 0;
}