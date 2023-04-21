
#include <bits/stdc++.h>
using namespace std;
#define mul(a) (a)*(a)


void chk(int r,int a,int b)
{
    if(r>=a*a&&r>=b*b) printf(r==mul(a+b)?"1\n":(r>mul(a+b)?"0\n":"2\n"));
    else printf(r==mul(a-b)?"1\n":(r<mul(a-b)?"0\n":"2\n"));
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2,r1,r2;
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        if(x1==x2&&y1==y2) printf(r1==r2?"-1\n":"0\n");
        else chk(mul(x1-x2)+mul(y1-y2),r1,r2);
    }
    return 0;
}
