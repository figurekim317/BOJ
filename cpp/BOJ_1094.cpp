#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,a[70];

int main(){
    freopen("input.txt","r",stdin);
    for(int i=1;i<=64;i++)
        for(int j=0;i>>j;j++) if(i>>j&1) a[i]++;
    cin>>n; cout<<a[n];

    return 0;
}