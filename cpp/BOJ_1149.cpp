#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define M 61
#define MOD 10007

int n,m,a[N][3];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m; a[i][0]=min(a[i-1][1],a[i-1][2])+m;
        cin>>m; a[i][1]=min(a[i-1][2],a[i-1][0])+m;
        cin>>m; a[i][2]=min(a[i-1][0],a[i-1][1])+m;
    }
    cout<<min(a[n][0],min(a[n][1],a[n][2]));
    return 0;
}
