#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,d[10]={6,2, 5, 5, 4, 5, 6, 3, 7, 5},ans[20][180];
char a[20];

void amel()
{
    memset(ans,255,sizeof(ans));
    ans[n+1][90]=1;
    for(int i=n;i;i--)
    {
        for(int j=a[i]+1;j<10;j++)
            if(ans[i+1][90+d[a[i]]-d[j]]>=0)
                {
                    ans[i][90]=j;
                    for(int k=i-1;k;k--) ans[k][90]=a[k];
                    return;
                }
        for(int j=9;j>=0;j--)
            for(int k=0;k<180;k++) if(ans[i+1][k]>=0) ans[i][k+d[j]-d[a[i]]]=j;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",a+1);
    for(int i=1;a[i];i++) a[i]-='0',n++;
    ll bef=0,aft=0,p=1;
    for(int i=n;i;i--,p*=10) bef+=p*a[i];
    amel(); p/=10;
    for(int i=1,dap=90;i<=n;i++,p/=10)
        aft+=p*ans[i][dap],
        dap+=d[a[i]]-d[ans[i][dap]];
    p=1; while(n--) p*=10;
    printf("%lld",aft>bef?aft-bef:aft+p-bef);
    return 0;
}
