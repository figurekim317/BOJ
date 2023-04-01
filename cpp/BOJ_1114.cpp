#include<stdio.h>
#include<algorithm>

using namespace std;

int l,k,c,a[10010]={0},b[10010]={0};

bool check(int x){
    int i,t=0,cnt=0;
    for(i=0;i<=k;i++){
        if(b[i]<=x){
            if(t+b[i]>x){
                t=0;
                cnt=cnt+1;
                i=i-1;
            }
            else{
                t=t+b[i];
            }
        }
        else{
            return 1;
        }
    }
    return cnt>c;
}

int tree(int s,int f){
    int x;
    while(s<f){
        x=(s+f)/2;
        if(check(x)){
            s=x+1;
        }
        else{
            f=x;
        }
    }
    return s;
}

int main(){
    int i,x,t,cnt,y;
    scanf("%d %d %d",&l,&k,&c);
    for(i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+k);
    b[0]=a[0];
    for(i=1;i<k;i++){
        b[i]=a[i]-a[i-1];
    }
    b[k]=l-a[k-1];
    x=tree(0,l);
    t=0;
    cnt=0;
    for(i=k;i>=0;i--){
        if(t+b[i]>x){
            y=i;
            i=i+1;
            cnt=cnt+1;
            t=0;
        }
        else{
            t=t+b[i];
        }
    }
    if(c-cnt>0){
        y=0;
    }
    printf("%d %d",x,a[y]);
}
