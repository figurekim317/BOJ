#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 10010
#define M 1010

int n;
map<int,int> a;
list<int> ans;

bool amel()
{
    list<int> tmp;
    for(auto i:a)
        if(i.ss>0) tmp.pb(i.ff);
    if(tmp.empty()) return true;
    int pv=INT_MAX;
    for(auto i:tmp)
    {
        if(pv==i||(!ans.empty()&&ans.back()+1==i)) continue;
        a[i]--; ans.pb(i);
        if(amel()) return true;
        a[i]++; ans.pop_back();
        pv=i;
    }
    return false;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=n,j;i--;) scanf("%d",&j),a[j]++;
    amel();
    for(auto i:ans) printf("%d ",i);
    return 0;
}