#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 61
#define MOD 10007

int n,m;

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=666;;i++)
    {
        int tmp=0;
        for(int j=i;j;j/=10)
        {
            if(j%10==6) tmp++;
            else tmp=0;
            if(tmp==3) {n--; break;}
        }
        if(!n) {cout<<i; return 0;}
    }
    return 0;
}
