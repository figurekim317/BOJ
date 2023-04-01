#include <bits/stdc++.h>
using namespace std;

int n,m,a[60],b[60],vis[60];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i),b[i]=a[i];
    sort(b,b+n);
    for(int i=0,s;i<n;i++)
        s=lower_bound(b,b+n,a[i])-b,printf("%d ",s+vis[s]),vis[s]++;
    return 0;
}
