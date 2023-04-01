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

int n,a[55],m;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",a+i);
    cin>>m;
    for(int i=0;i<n&&m>0;i++)
    {
        int t=max_element(a+i,a+min(n,i+m+1))-a;
        m-=t-i;
        for(int j=t;j>i;j--) swap(a[j],a[j-1]);
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}