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

int n;
double ans;
char a[10][5][3],qq,b[10][5][3]={35,35,35,35,46,35,35,46,35,35,46,35,35,35,35,46,46,35,46,46,35,46,46,35,46,46,35,46,46,35,35,35,35,46,46,35,35,35,35,35,46,46,35,35,35,35,35,35,46,46,35,35,35,35,46,46,35,35,35,35,35,46,35,35,46,35,35,35,35,46,46,35,46,46,35,35,35,35,35,46,46,35,35,35,46,46,35,35,35,35,35,35,35,35,46,46,35,35,35,35,46,35,35,35,35,35,35,35,46,46,35,46,46,35,46,46,35,46,46,35,35,35,35,35,46,35,35,35,35,35,46,35,35,35,35,35,35,35,35,46,35,35,35,35,46,46,35,35,35,35};

bool chk(int p,int q)
{
    for(int i=0;i<5;i++)
        for(int j=0;j<3;j++)
            if(a[p][i][j]=='#'&&b[q][i][j]=='.') return 0;
    return 1;
}

int main(){
    freopen("input.txt","r",stdin);
//    for(int i=0;i<5;i++)
//        for(int j=0;j<10;j++)
//        {
//            for(int k=0;k<3;k++)
//                cin>>a[j][i][k];
//            if(j!=9) cin>>qq;
//        }
//    for(int i=0;i<10;i++)
//        for(int j=0;j<5;j++)
//            for(int k=0;k<3;k++) printf("%d,",a[i][j][k]);
//    return 0;
    cin>>n;
    for(int i=0;i<5;i++)
        for(int k=n;k--;)
        {
            for(int j=0;j<3;j++) cin>>a[k][i][j];
            if(k) cin>>qq;
        }
    for(int i=0,r=1;i<n;i++,r*=10)
    {
        int tmp=0,cnt=0;
        for(int j=0;j<10;j++)
            if(chk(i,j)) tmp+=j,cnt++;
        if(!cnt) {printf("-1"); return 0;}
        ans+=(double)tmp/cnt*r;
    }
    printf("%.5f",ans);
    return 0;
}