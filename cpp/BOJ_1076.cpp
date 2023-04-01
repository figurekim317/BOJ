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

string a,b,c;
map<string,int> n;

int main(){
    freopen("input.txt","r",stdin);
    n["black"]=0;
    n["brown"]=1;
    n["red"]=2;
    n["orange"]=3;
    n["yellow"]=4;
    n["green"]=5;
    n["blue"]=6;
    n["violet"]=7;
    n["grey"]=8;
    n["white"]=9;
    cin>>a>>b>>c;
    if(a!="black") cout<<n[a];
    cout<<n[b];
    if(a!="black"||b!="black") for(int i=n[c];i--;) cout<<'0';
    return 0;
}