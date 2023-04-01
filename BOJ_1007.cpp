#include <bits/stdc++.h>
using namespace std;

int n;
long long ans=LLONG_MAX;
pair<int,int> a[30];

int main(){
  //  freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    for(int ii=0;ii<te;ii++,ans=LLONG_MAX)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d %d",&a[i].first,&a[i].second);
        for(int i=0;i<1<<n;i++)
        {
            int cnt=0;
            for(int j=1;j<=i;j<<=1) if(i&j) cnt++;
            if(cnt!=n/2) continue;
            int x=0,y=0;
            for(int j=1;j<=n;j++)
            {
                x+=i&1<<j-1?a[j].first:-a[j].first;
                y+=i&1<<j-1?a[j].second:-a[j].second;
            }
            ans=min(ans,(long long)x*x+(long long)y*y);
        }
        printf("%.12f\n",sqrt((double)ans));
    }
    return 0;
}
