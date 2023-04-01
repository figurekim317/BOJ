#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define N 1010
#define M 100010
#define MOD 15746

int n,m;

int amel(int p)
{
    int ret=p;
    for(;p;p/=10) ret+=p%10;
    return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<n;i++) if(amel(i)==n) {cout<<i; return 0;}
    printf("0");
    return 0;
}
