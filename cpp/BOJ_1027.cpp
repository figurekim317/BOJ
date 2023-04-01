#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[55],ans;

bool amel(int p,int s,int t)
{
    if(!s) return true;
    ll ret=(ll)(a[t]-a[p])*(ll)abs(p-s)-(ll)(a[s]-a[p])*(ll)abs(p-t);
    return ret>0;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=i-1,m=0;j>0;j--)
            if(amel(i,m,j)) cnt++,m=j;

        for(int j=i+1,m=0;j<=n;j++)
            if(amel(i,m,j)) cnt++,m=j;

        ans=max(ans,cnt);
    }

    printf("%d",ans);
    return 0;
}
