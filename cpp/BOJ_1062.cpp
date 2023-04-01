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
#define M 100010

int n,m,b[21],ans,c[30];
string a[55];

bool chk(char p)
{
    if(p=='a'||p=='n'||p=='t'||p=='i'||p=='c') return 1;
    return b[c[p-'a']];
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]=a[i].substr(4,a[i].length()-8);
    if(m<5) {printf("0"); return 0;}
    m-=5;
    for(int i='a',cnt=0;i<='z';i++)
        if(i!='a'&&i!='n'&&i!='t'&&i!='i'&&i!='c') c[i-'a']=cnt++;
    for(int i=0;i<m;i++) b[i]=1;
    do
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int flag=1;
            for(auto j:a[i]) if(!chk(j)) {flag=0; break;}
            cnt+=flag;
        }
        ans=max(ans,cnt);
    }while(prev_permutation(b,b+21));
    cout<<ans;
    return 0;
}
