#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,a[10],p,q;
ll ans=1,b[]={1,1,3,15,105,1155};

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    while(~scanf("%1d%1d",&p,&q)) a[p]++,a[q]++;
    for(int i=10;i--;)
    {
        if(a[i]&1) {printf("0"); return 0;}
        else ans*=b[a[i]>>1];
    }
    cout<<ans;
    return 0;
}