#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<=i;j++) printf("*");
    return 0;
}
