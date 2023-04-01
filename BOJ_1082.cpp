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

int n,a[15],m,k;

int main(){
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",a+i);
    cin>>m;
    auto t=min_element(a,a+n);
    if(t==a)
    {
        if(n==1||m<*min_element(a+1,a+n)) {printf("0"); return 0;}
        k=(m-*min_element(a+1,a+n))/(*t)+1;
    }
    else
        k=m/(*t);
    for(int i=n-1,j;i>=0;i--)
    {
        for(j=m/a[i];j;j--)
            if((m-j*a[i])/(*min_element(a,a+i))+j>=k) break;
        m-=j*a[i]; k-=j;
        while(j--) printf("%d",i);
    }
    return 0;
}