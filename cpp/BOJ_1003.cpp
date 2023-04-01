#include <bits/stdc++.h>
using namespace std;

int n,m,a[50];

int main(){
   // freopen("input.txt","r",stdin);
    a[0]=a[2]=1;
    for(int i=3;i<=41;i++) a[i]=a[i-1]+a[i-2];
    scanf("%d",&n);
    for(int i=0,s;i<n;i++)
        scanf("%d",&s),printf("%d %d\n",a[s],a[s+1]);
    return 0;
}
