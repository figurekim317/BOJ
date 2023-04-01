#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 15746

int n,m=1,k,b;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(n--) b=m,m=(m+k)%MOD,k=b;
    printf("%d",m);
    return 0;
}
