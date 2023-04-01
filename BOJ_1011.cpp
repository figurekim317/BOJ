#include <bits/stdc++.h>
using namespace std;

int n,m,a[100010];

int main(){
  //  freopen("input.txt","r",stdin);

    for(int i=0,cnt=0;cnt<92681;i+=(cnt-1)/2+1)
        a[cnt++]=i;
    int te;
    scanf("%d",&te);
    for(int ii=0;ii<te;ii++)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",lower_bound(a+1,a+92681,m-n)-a);
    }
    return 0;
}
