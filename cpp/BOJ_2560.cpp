#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int a,b,d,n,k[1000010]={1},ans;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>a>>b>>d>>n;
    k[a]=1;
    for(int i=a+1;i<=n;i++)
    {
        if(i>=b) k[i]=(k[i-1]+k[i-a]-k[i-b]+MOD)%MOD;
        else k[i]=(k[i-1]+k[i-a])%MOD;
    }
    for(int i=max(0,n-d+1);i<=n;i++) ans+=k[i];
//    for(int i=0;i<=n;i++) printf("%d\n",k[i]);
    cout<<ans%MOD;
    return 0;
}