#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 2610
#define MOD 1000000007

char a[N],codon[55][5],name[55][25];
int n,vis[55],cnt;
ll ans[N];
list<int> ed[55];

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%s",a);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s %s",codon[i],name[i]);
    for(int i=1,flag=0;i<=n;i++,cnt+=flag,flag=0)
        for(int j=i;j<=n;j++)
            if(!vis[j]&&!strcmp(name[i],name[j]))
                flag=1,vis[j]=1,ed[cnt].push_back(j);
    n=strlen(a); ans[0]=1ll;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            int v=INT_MAX;
            for(int k:ed[j])
            {
                int x=i,flag=0;
                for(int g=0;g<3;g++,x++)
                {
                    while(x<n&&a[x]!=codon[k][g]) x++;
                    if(a[x]!=codon[k][g]) {flag=1; break;}
                }
                if(!flag) v=min(v,x);
            }
            if(v!=INT_MAX) ans[v]+=ans[i],ans[v]%=MOD;
        }
        ans[n]+=ans[i]; ans[n]%=MOD;
    }
    printf("%lld",(ans[n]+MOD-1)%MOD);
    return 0;
}
