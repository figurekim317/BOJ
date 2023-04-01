#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 600921647
#define N 500000
#define M 3010

int n,m,a[2][N+10];

int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n;
    memset(a,-1,sizeof(a));
    a[n&1][0]=0;
    for(int i;n--;)
    {
        cin>>i;
        memcpy(a[n&1],a[!(n&1)],sizeof(int)*N);
        for(int j=N;j--;)
            if(~a[!(n&1)][j])
            {
                if(j+i<N) a[n&1][j+i]=max(a[n&1][j+i],a[!(n&1)][j]);
                a[n&1][abs(j-i)]=max(a[n&1][abs(j-i)],a[!(n&1)][j]+min(i,j));
            }
    }
    if(a[0][0]>0) cout<<a[0][0];
    else printf("-1");

    /*
}//*/
    return 0;
}
