#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m;
vector<vpii> a;
vi w;
ll ans;

bool chk(int p,int q) {return 0<=p&&p<n&&0<=q&&q<m;}

void amel(pii p,pii q)
{
    int x=0,y=0,Mx=0,My=0,mx=0,my=0;
    x+=p.ff; y+=p.ss; Mx=max(Mx,x); My=max(My,y); mx=min(mx,x); my=min(my,y);
    x+=q.ff; y+=q.ss; Mx=max(Mx,x); My=max(My,y); mx=min(mx,x); my=min(my,y);
    x-=p.ff; y-=p.ss; Mx=max(Mx,x); My=max(My,y); mx=min(mx,x); my=min(my,y);
    if(Mx!=mx && Mx-mx<=n && My!=my && My-my<=m)
        ans += (ll)(n-(Mx-mx))*(m-(My-my));
}

void Solve()
{
    cin>>m>>n;
    n++; m++;
    set<int> u;
    for(int i=n+1;i--;)
        for(int j=m+1;j--;) u.insert(i*i+j*j);
    w.insert(w.begin(), u.begin(), u.end());
    a.resize(w.size());
    for(int i=-n;i<=n;i++)
        for(int j=-m;j<=m;j++)
        {
            int t=lower_bound(w.begin(),w.end(),i*i+j*j)-w.begin();
            a[t].pb(mp(i,j));
        }
    for(auto ii:a)
        for(auto i:ii)
            for(auto j:ii)
                if(i!=j && (i.ff!=-j.ff||i.ss!=-j.ss))
                    amel(i,j);
    cout<<(ans>>3);
}

int main(){
//    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
