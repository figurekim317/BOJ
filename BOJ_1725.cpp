#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,m=-10,k,s=1;
    stack<pair<int, int> > a;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &k);
        s=i;
        while(!a.empty() && a.top().second > k){
            if(m<(i-a.top().first)*a.top().second){
                m=(i-a.top().first)*a.top().second;
            }
            s=a.top().first;
            a.pop();
        }
        if(a.empty() || a.top().second<k){
            a.push({s,k});
        }
    }
    k=0;
    i=n+1;
    while(!a.empty()){
        if(m<(i-a.top().first)*a.top().second){
            m=(i-a.top().first)*a.top().second;
        }
        s=a.top().first;
        a.pop();
    }
    printf("%d", m);
    return 0;
}