#include <bits/stdc++.h>
using namespace std;



int main(){
    int n,x,y,ans=0;
    scanf("%d %d %d",&n,&x,&y);
    for(;n;n--)
    {
        if(x>=1<<(n-1))
        {
            x-=1<<(n-1);
            if(y<1<<(n-1)) ans+=1<<(2*n-1);
            else ans+=(1<<(2*n))-(1<<(2*n-2)),y-=1<<(n-1);
        }
        else if(y>=1<<(n-1)) ans+=1<<(2*n-2),y-=1<<(n-1);
    }
    printf("%d",ans);
    return 0;
}
