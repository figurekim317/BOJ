#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1'000'000'009

int n,m;

pair<double,double> w;
bool cmp(const pair<double,double> &lhs,const pair<double,double> &rhs)
{
    auto p=mp(lhs.ff-w.ff,lhs.ss-w.ss),q=mp(rhs.ff-w.ff,rhs.ss-w.ss);
    return p.ff*q.ss-p.ss*q.ff>0;
}

void Solve()
{
//    cin>>n>>m;
    for(int x1,y1,z1,x2,y2,z2,a,b,c;;)
    {
        cin>>x1>>y1>>z1>>x2>>y2>>z2>>a>>b>>c;
        if(cin.eof()) break;
        if((x1==x2)+(y1==y2)+(z1==z2)>1) {cout<<"0\n"; continue;}
        x1-=a; x2-=a; y1-=b; y2-=b; a=b=0;
        if((!y1&&!y2)||(!x1&&!x2)) {cout<<"0\n"; continue;}
        if(z1>z2) swap(x1,x2),swap(y1,y2),swap(z1,z2);
        if(z1>=c) {cout<<"0\n"; continue;}
        if(z2>=c) {cout<<"-1\n"; continue;}
        vector<pair<double,double>> p,q;
        for(int d=8;d--;)
        {
            double t=d&1?(double)c/(c-z1):(double)c/(c-z2);
            p.pb(mp(d&2?t*x1:t*x2,d&4?t*y1:t*y2));
        }
        sort(p.begin(),p.end());
        unique(p.begin(),p.end());
        q.pb(w=p[0]);
        for(;;)
        {
            auto t=w==p[0]?p[1]:p[0];
            for(auto &i:p)
                if(i!=t&&cmp(i,t)) t=i;
            if(q[0]==t) break;
            q.pb(w=t);
        }
        double ans=0;
        for(int i=q.size()-1;i>1;i--)
        {
            auto u=mp(q[i].ff-q[0].ff,q[i].ss-q[0].ss),v=mp(q[i-1].ff-q[0].ff,q[i-1].ss-q[0].ss);
            ans+=abs(u.ff*v.ss-u.ss*v.ff);
        }
        cout<<fixed;
        cout.precision(6);
        cout<<ans/2<<'\n';
    }
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){Init(01);
//    int tc; cin>>tc; for(int i=1;i<=tc;i++)
//    cout<<"Case #"<<i<<'\n',
    Solve();
    return 0;
}
