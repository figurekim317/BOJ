#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0,sx,sy,ex,ey,t,ans=0;i<n;i++,ans=0)
    {
        scanf("%d %d %d %d %d",&sx,&sy,&ex,&ey,&t);
        for(int j=0,x,y,r;j<t;j++)
            scanf("%d %d %d",&x,&y,&r),
            ans+=((sx-x)*(sx-x)+(sy-y)*(sy-y)<r*r)^((ex-x)*(ex-x)+(ey-y)*(ey-y)<r*r);
        printf("%d\n",ans);
    }
    return 0;
}
