#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 25
#define M 0
#define MOD 10007

int n,m,a[N],ans;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<1<<n;i++)
    {
        int tmp=0;
        for(int j=0;j<n;j++)
            if(i>>j&1) tmp+=a[j];
        ans+=(tmp==m);
    }
    cout<<ans;
    return 0;
}
