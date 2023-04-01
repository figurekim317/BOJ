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

int n,m,a[1'000'010]={1,1};
vi b;

int amel(int p)
{
    for(auto &i:b)
    {
        if(i>p) break;
        if(!a[p-i]) return i;
    }
    return 0;
}

void Solve()
{
    srand(23792);
    cin>>n;
    if(n<8) {cout<<-1; return;}
    b.pb(2);
    for(int i=4;i<=n;i+=2) a[i]=1;
    for(int i=3;i<=n;i+=2)
        if(!a[i])
        {
            b.pb(i);
            for(int j=i*3;j<=n;j+=i<<1) a[j]=1;
        }
    for(int ii=500;ii--;)
    {
        int i=rand()%(n-3)+2;
        int p=amel(i),q=amel(n-i);
        if(p&&q)
        {
            cout<<p<<' '<<i-p<<' '<<q<<' '<<n-i-q;
            return;
        }
    }
    cout<<-1;
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
