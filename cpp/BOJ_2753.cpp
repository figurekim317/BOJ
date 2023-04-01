#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 55
#define MOD 1000000007

int n,m;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    printf("%d",n%400==0||(n%4==0&&n%100));
    return 0;
}
