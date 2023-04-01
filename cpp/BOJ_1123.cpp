#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 600921647
#define N 200010
#define M 3010

int n,m,a[15][15],gen[15][15],st,ed;

struct mat
{
    ll a[12][12][12][12];
}e,mp[35];

void mul(mat *p,mat *q)
{
    mat ret;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<m;k++)
                for(int l=0;l<m;l++) ret.a[i][j][k][l]=0;
            for(int k=0;k<9;k++)
                for(int ii=0;ii<m;ii++)
                    for(int jj=0;jj<m;jj++)
                        for(int l=0;l<m;l++)
                        {
                            ret.a[i][j][ii][jj]+=p->a[i][k][ii][l]*q->a[k][j][l][jj];
                            ret.a[i][j][ii][jj]%=MOD;
                        }
        }
    *p=ret;
}

ll mpow(int q)
{
    mat p=e;
    for(int i=0;q>>i;i++)
        if(q>>i & 1) mul(&p,mp+i);
    ll ret=0;
    for(int i=0;i<m-1;i++)
    {
        ret+=p.a[8][8][i][m-1];
        ret%=MOD;
    }
    return ret;
}


int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n;
    for(int i=n,j,k;i--;) cin>>j>>k,a[j][k]++;
    cin>>m;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            gen[i][j]= c=='Y';
        }
    cin>>st>>ed;

    a[m][1]=1;
    for(int i=0;i<=m;i++) gen[m][i]=1;
    m++;

    for(int i=0;i<9;i++)
        for(int j=0;j<m;j++) e.a[i][i][j][j]=1;

    for(int i=0;i<8;i++)
        for(int j=0;j<m;j++) mp[0].a[i][i+1][j][j]=1;

    for(int i=0;i<9;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++)
                if(gen[k][j]) mp[0].a[8][i][j][k]=a[j][9-i];

    for(int i=1;ed>>i;i++)
        mp[i]=mp[i-1],mul(mp+i,mp+i);

    cout<<(mpow(ed)-mpow(st-1)+MOD)%MOD;

    /*
}//*/
    return 0;
}
