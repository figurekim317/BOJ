#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 20010
#define M 0
#define MOD 15746

int n,m;
string a[N];

bool comp(string lhs,string rhs)
{
    if(lhs.size()!=rhs.size()) return lhs.size()<rhs.size();
    return lhs<rhs;
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,comp);
    for(int i=0;i<n;i++)
        if(i==n-1||a[i]!=a[i+1]) cout<<a[i]<<"\n";
    return 0;
}
