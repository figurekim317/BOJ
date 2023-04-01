#include <stdio.h>
#include <algorithm>
int n,a[55],b[55],d;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",b+i);
    std::sort(a,a+n); std::sort(b,b+n);
    for(int i=0;i<n;i++) d+=a[i]*b[n-i-1];
    printf("%d",d);
    return 0;
}
