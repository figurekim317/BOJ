#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 1000000007

int n,m,a[N];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;i++) printf("%d\n",a[i]);
    return 0;
}
