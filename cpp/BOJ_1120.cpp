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

int n=INT_MAX;
string a,b;

int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>a>>b;
    for(int i=b.size()-a.size()+1;i--;)
    {
        int cnt=0;
        for(int j=a.size();j--;) cnt+=a[j]!=b[i+j];
        n=min(n,cnt);
    }
    cout<<n;

    /*
}//*/
    return 0;
}
