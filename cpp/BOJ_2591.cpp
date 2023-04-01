#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 3010

string a;
int ans[45]={1,1};

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>a;
    if(a[0]=='0') {printf("0"); return 0;}
    for(int i=1;i<a.length();i++)
    {
        int t=(a[i-1]-'0')*10+a[i]-'0';
        if(10<=t&&t<=34) ans[i+1]+=ans[i-1];
        if(a[i]!='0') ans[i+1]+=ans[i];
    }
    cout<<ans[a.length()];
    return 0;
}