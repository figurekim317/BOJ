#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 55
#define MOD 1000000007

int n,m;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    if(n>m) printf(">");
    else if(n<m) printf("<");
    else printf("==");
    return 0;
}
