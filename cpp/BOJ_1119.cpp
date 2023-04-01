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
#define N 200010
#define M 3010

int n,m,a[55][55],vis[55],loop,cnt;

void dfs(int p,int par)
{
    if(vis[p]) return;
    vis[p]=vis[par]+1;
    for(int i=0;i<n;i++)
        if(a[i][p]&&i!=par)
        {
            if(vis[i]&&vis[i]<vis[p]) loop++;
            else dfs(i,p);
        }
}

int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n;
    char cc;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>cc,a[i][j]=cc=='Y';
    if(n==1) {printf("0"); return 0;}
    for(int i=0;i<n;i++)
    {
        int flag=1;
        for(int j=0;j<n;j++) if(a[i][j]) {flag=0; break;}
        if(flag) {printf("-1"); return 0;}
    }
    for(int i=0;i<n;i++)
        if(vis[i]==0) cnt++,dfs(i,i);
    if(loop+1<cnt) printf("-1");
    else cout<<cnt-1;

    /*
}//*/
    return 0;
}
