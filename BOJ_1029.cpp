#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[20][20],ans[15][1<<15];
vector<int> d[16];

int amel()
{
    for(int ret=n;;ret--)
        for(int i=0;i<n;i++)
            for(int j:d[ret]) if(ans[i][j]) return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%1d",a[i]+j),a[i][j]++;
    for(int i=0;i<1<<n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            cnt+=i>>j&1;
        d[cnt].push_back(i);
    }
    ans[0][1]=1;
    for(int len=1;len<=n;len++)
        for(int i=0;i<n;i++)
            for(int v:d[len])
                if(ans[i][v])
                {
                    for(int j=0;j<n;j++)
                        if(!(v>>j&1)&&a[i][j]>=ans[i][v])
                            ans[j][v|1<<j]=ans[j][v|1<<j]?min(ans[j][v|1<<j],a[i][j]):a[i][j];
                }
    printf("%d",amel());
    return 0;
}
