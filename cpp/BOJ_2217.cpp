#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 61
#define MOD 10007

int n,m,a[N];

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) m=max(m,a[i]*(n-i));
    cout<<m;
    return 0;
}
