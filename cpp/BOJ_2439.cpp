#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1000010
#define MOD 1000000007

int n,m,k;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++,puts(""))
    {
        for(int j=0;j<n-i-1;j++) printf(" ");
        for(int j=0;j<i+1;j++) printf("*");
    }
    return 0;
}
