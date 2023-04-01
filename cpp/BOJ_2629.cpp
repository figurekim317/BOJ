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
#define M 3010

int n,m,a[40510][35]={1};

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0,x;i<n;i++)
    {
        cin>>x;
        for(int j=0;j<=40500;j++)
            if(a[j][i])
            {
                a[j][i+1]=1;
                if(j+x<=40500) a[j+x][i+1]=1;
                a[abs(j-x)][i+1]=1;
            }
    }
    cin>>m;
    for(int i;m--;) cin>>i,printf(a[i][n]?"Y ":"N ");

    return 0;
}