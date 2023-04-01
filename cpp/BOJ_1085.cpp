#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m,x,y;

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m>>x>>y;
    cout<<min(min(n,x-n),min(m,y-m));
    return 0;
}