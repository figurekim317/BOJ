#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 1000000000

struct word
{
    int val=0;
    vector<pair<string,int> > a;
};

int n,m;
map<string,int> a;
list<pair<string,word> > b;

int main()
{
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    string c;
    for(int i=n,j;i--;)
    {
        cin>>c>>j;
        a[c]=j;
    }
    for(int i=m;i--;)
    {
        cin>>c;
        auto p=c.find("=");
        string d=c.substr(0,p);
        c.erase(0,p+1);
        word t;
        while((p=c.find("+"))!=string::npos)
        {
            t.a.pb({c.substr(1,p-1),c[0]-'0'});
            c.erase(0,p+1);
        }
        t.a.pb({c.substr(1,c.length()-1),c[0]-'0'});
        b.pb({d,t});
    }
    for(int tc=m;tc--;)
        for(auto i:b)
        {
            int tmp=i.ss.val,flag=0;
            for(auto j:i.ss.a)
            {
                if(a.find(j.ff)==a.end()) {flag=1; break;}
                if(tmp>M||a[j.ff]>M/j.ss) tmp=M+1;
                else tmp+=a[j.ff]*j.ss;
            }
            if(flag) continue;
            tmp=min(tmp,M+1);
            if(a.find(i.ff)==a.end()||a[i.ff]>tmp) a[i.ff]=tmp;
        }
    if(a.find("LOVE")==a.end()) printf("-1");
    else cout<<a["LOVE"];
    return 0;
}
