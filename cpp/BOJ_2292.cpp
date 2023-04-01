#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 0
#define MOD 15746

int n,m;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=(int)sqrt((double)n/6);;i++)
        if(n<=i*(i+1)*3+1) {cout<<i+1; return 0;}
    return 0;
}
