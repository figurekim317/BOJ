#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define M 61
#define MOD 10007

int n,m,a[N];

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(;n;n/=10) a[m++]=n%10;
    sort(a,a+m);
    for(int i=m-1;i>=0;i--) cout<<a[i];
    return 0;
}
