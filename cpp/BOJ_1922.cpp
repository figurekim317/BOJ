#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define N 1010
#define M 100010
#define MOD 15746

int n,m,k,par[N],ans;
piii a[M];

int pfind(int p)
{
    if(par[p]==p) return p;
    return par[p]=pfind(par[p]);
}

bool uni(int p,int q)
{
    p=pfind(p); q=pfind(q);
    if(p==q) return 0;
    par[q]=p;
    return 1;
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=0;i<m;i++) cin>>a[i].second.first>>a[i].second.second>>a[i].first;
    sort(a,a+m);
    for(int i=0;i<m;i++)
        if(uni(a[i].second.first,a[i].second.second)) ans+=a[i].first;
    cout<<ans;
    return 0;
}
