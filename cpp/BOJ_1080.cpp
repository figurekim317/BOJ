#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m,a[55][55],b[55][55],ans;
int dx[]={-1,-1,-1,0,0,1,1,0,1},dy[]={-1,0,1,-1,1,-1,0,0,1};

bool chk(int p,int q)
{
    return 0<=p&&p<n&&0<=q&&q<m;
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%1d",a[i]+j);
    for(int i=0,k;i<n;i++)
        for(int j=0;j<m;j++) scanf("%1d",&k), a[i][j]^=k;
    for(int i=0;i<n-2;i++)
        for(int j=0;j<m-2;j++)
        {
            b[i+1][j+1]=a[i][j];
            for(int k=0;k<8;k++)
                if(chk(i+dx[k],j+dy[k]))
                    b[i+1][j+1]^=b[i+dx[k]][j+dy[k]];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int tmp=0;
            for(int k=0;k<9;k++)
                if(chk(i+dx[k],j+dy[k])) tmp^=b[i+dx[k]][j+dy[k]];
            if(tmp!=a[i][j]) {printf("-1"); return 0;}
        }
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++) ans+=b[i][j];
    cout<<ans;
    return 0;
}