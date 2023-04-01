#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,a,b,c,p,q;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    cin>>a>>b>>c;
    if(n==2&&a==b) {printf("%d",a); return 0;}
    if(n<3) {printf("A"); return 0;}
    if(a==b)
    {
        if(b==c) p=1;
        else {printf("B"); return 0;}
    }
    else
    {
        if((c-b)%(b-a)) {printf("B"); return 0;}
        p=(c-b)/(b-a);
        if(b-a*p!=c-b*p) {printf("B"); return 0;}
        q=b-a*p;
    }
    n-=3;
    for(int i;n--;)
    {
        c=c*p+q;
        cin>>i;
        if(i!=c) {printf("B"); return 0;}
    }
    printf("%d",c*p+q);
    return 0;
}