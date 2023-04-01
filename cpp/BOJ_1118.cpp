#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 200010
#define M 3010

int n,m,k,pre;
ll ans;
set<pii> col;
vector<pii> paint[55];
set<int> now;

struct cmp
{
    bool operator()(const pii lhs,const pii rhs)const
    {
        return paint[lhs.ff][lhs.ss].ff>paint[rhs.ff][rhs.ss].ff;
    }
};

void amel(int p)
{
    priority_queue<pii,vector<pii>,cmp> q;
    for(auto i:now) q.push({i,0});
    ll ret=p-pre;
    int tmp=-1,cnt=0;
    while(!q.empty())
    {
        auto i=q.top(); q.pop();
        if(paint[i.ff].size()>i.ss+1) q.push({i.ff,i.ss+1});
        if(paint[i.ff][i.ss].ss)
        {
            cnt--;
            if(!cnt) ans+=ret*(paint[i.ff][i.ss].ff-tmp),tmp=-1;
        }
        else
        {
            cnt++;
            if(!~tmp) tmp=paint[i.ff][i.ss].ff;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n>>m>>k;
    for(int i=k,f,x1,x2,c,yy1,yy2;i--;)
    {
        cin>>f>>c>>x1>>yy1>>x2>>yy2;
        c=m/(c+1);
        if(x1==0) {col.insert({max(0,f-x2),i}); col.insert({min(n,f+x2),i});}
        else
        {
            if(x1<n-f) {col.insert({f+x1,i}); col.insert({min(n,f+x2),i});}
            if(x1<f) {col.insert({max(0,f-x2),i}); col.insert({f-x1,i});}
        }
        for(int j=0;j<m;j+=2*c)
        {
            paint[i].pb({j+yy1,0}); paint[i].pb({j+yy2,1});
            if(j+c<m) {paint[i].pb({j+2*c-yy2,0}); paint[i].pb({j+2*c-yy1,1});}
        }
    }
    for(auto i:col)
    {
        if(pre!=i.ff)
        {
            amel(i.ff);
            pre=i.ff;
        }
        if(now.find(i.ss)==now.end()) now.insert(i.ss);
        else now.erase(i.ss);
    }
    cout<<(ll)n*m-ans;

    /*
}//*/
    return 0;
}
