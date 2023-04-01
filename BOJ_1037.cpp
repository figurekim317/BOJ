#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 55
#define MOD 1000000007

int n,small=INT_MAX,big;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0,s;i<n;i++)
        scanf("%d",&s),small=min(small,s),big=max(big,s);
    printf("%d",small*big);
    return 0;
}
