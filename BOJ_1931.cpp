#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define MOD 15746

int n,m,ans;
pii a[N];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d",&a[i].second,&a[i].first);
    sort(a,a+n);
    for(int i=0;i<n;i++)
        if(m<=a[i].second) ans++,m=a[i].first;
    printf("%d",ans);
    return 0;
}
