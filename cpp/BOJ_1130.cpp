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

int n,m,a[55][55],ans[51][51][51][51];
pii s,e,f;
queue<pii> bfs;

int chk(int nx,int ny,int x,int y)
{
    if(0<=x&&x<n&&0<=y&&y<m&&ans[nx][ny][x][y]) return 0;

    int dr=0,ym=2*(x-nx),xm=-2*(y-ny);
    int v=-2*x*xm-2*y*ym;

    if(x<nx) dr=1, v-=xm;
    else v+=xm;

    if(y<ny) dr|=2, v-=ym;
    else v+=ym;

    while(1)
    {
        if(dr&1) assert(nx>=x);
        else assert(nx<=x);
        if(dr&2) assert(ny>=y);
        else assert(ny<=y);

        if(0>nx||nx>=n||0>ny||ny>=m) return 0;
        if(e.ff==nx&&e.ss==ny) return -1;

        if(a[nx][ny]) return 0;
        if(nx==x&&ny==y) return 1;

        int tmp=2*nx*xm+2*ny*ym+v;

        if(!tmp)
        {
            if(e.ff==nx + (dr&1 ? -1 : 1) && e.ss==ny) return -1;
            if(e.ff==nx && e.ss==ny + (dr&2 ? -1 : 1)) return -1;
        }

        if(tmp>=0)
        {
            switch(dr)
            {
                case 0: nx++; break;
                case 1: ny++; break;
                case 2: ny--; break;
                default: nx--;
            }
        }
        if(tmp<=0)
        {
            switch(dr)
            {
                case 0: ny++; break;
                case 1: nx--; break;
                case 2: nx++; break;
                default: ny--;
            }
        }
    }
}

void Solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            switch(c)
            {
                case 'X': a[i][j]=1; break;
                case 'S': s={i,j}; break;
                case 'F': e={i,j};
            }
        }
    cin>>f.ff>>f.ss;

    bfs.push({s.ff-f.ff,s.ss-f.ss}); bfs.push(s);
    bool flag=false;
    while(!bfs.empty())
    {
        assert(bfs.size()<2000000);

        pii pre=bfs.front(); bfs.pop();
        pii t=bfs.front(); bfs.pop();

        int now=1;
        if(flag) now=ans[pre.ff][pre.ss][t.ff][t.ss]+1;
        else flag=true;

        for(int dx:{-1,0,1})
            for(int dy:{-1,0,1})
            {
                int nx=2*t.ff-pre.ff+dx,ny=2*t.ss-pre.ss+dy;
                int tmp=chk(t.ff,t.ss,nx,ny);
                if(!~tmp) {cout<<now; return;}
                if(tmp)
                {
                    ans[t.ff][t.ss][nx][ny]=now;
                    bfs.push(t); bfs.push({nx,ny});
                }
            }
    }
    cout<<-1;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
