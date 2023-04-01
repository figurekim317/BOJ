#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    n=n/100*100;
    if(n%m) printf("%02d",m-n%m);
    else printf("00");
    return 0;
}