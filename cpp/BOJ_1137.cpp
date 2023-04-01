#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,F[55][55],Y[55][55],ans=-1;
char a[55][55];
string w;
pii fs, ys;

int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool rng(int p, int q) {return 0<=p&&p<n&&0<=q&&q<m&&a[p][q]!='#';}

void Solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>a[i][j];
    cin>>w;
    memset(F, 1, sizeof(F));
    memset(Y, 1, sizeof(Y));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='X') F[i][j]=Y[i][j]=-1;
            if(a[i][j]=='F') fs={i,j};
            if(a[i][j]=='Y') ys={i,j};
        }
    for(auto &i:w)
        switch(i)
        {
            case 'S': i=2; break;
            case 'N': i=3; break;
            case 'E': i=0; break;
            default: i=1;
        }
    for(int i=w.size(); i--; )
    {
        int Fn[55][55], Yn[55][55];
        memcpy(Fn, F, sizeof(F));
        memcpy(Yn, Y, sizeof(Y));
        for(int x=n; x--;)
            for(int y=m; y--; )
            {
                int nx=x+dx[w[i]], ny=y+dy[w[i]];
                if(rng(nx,ny))
                {
                    Fn[x][y]=min(Fn[x][y], max(i, F[nx][ny]));
                    Yn[x][y]=min(Yn[x][y], max(i, Y[nx][ny]));
                }
            }
        if(Fn[fs.ff][fs.ss] > Yn[ys.ff][ys.ss]) ans=i;
        memcpy(F, Fn, sizeof(F));
        memcpy(Y, Yn, sizeof(Y));
    }
    cout<<ans;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
