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

char n;
int ans;

int main(){
    freopen("input.txt","r",stdin);
    for(int i=8;i--;)
        for(int j=8;j--;)
            cin>>n,ans+=(i&1)==(j&1)&&n=='F';
    cout<<ans;
    return 0;
}