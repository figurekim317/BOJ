#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010

int n,kx,ky,sx,sy;
string a;

int main()
{
 //   freopen("input.txt","r",stdin);
    cin>>a; kx=a[0]-'A'; ky=a[1]-'1';
    cin>>a; sx=a[0]-'A'; sy=a[1]-'1';
    if(kx==sx&&ky==sy) return 1;
//    printf("%d %d %d %d\n",kx,ky,sx,sy);
    for(cin>>n;n--;)
    {
        cin>>a;
        if(a=="R")
        {
            if(kx<7) kx++;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(sx==7) kx--;
                else sx++;
            }
        }
        else if(a=="L")
        {
            if(kx) kx--;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(sx) sx--;
                else kx++;
            }
        }
        else if(a=="B")
        {
            if(ky) ky--;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(sy) sy--;
                else ky++;
            }
        }
        else if(a=="T")
        {
            if(ky<7) ky++;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(sy==7) ky--;
                else sy++;
            }
        }
        else if(a=="RT")
        {
            if(kx<7&&ky<7) kx++,ky++;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(sx==7||sy==7) kx--,ky--;
                else sx++,sy++;
            }
        }
        else if(a=="LT")
        {
            if(kx&&ky<7) kx--,ky++;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(!sx||sy==7) kx++,ky--;
                else sx--,sy++;
            }
        }
        else if(a=="RB")
        {
            if(kx<7&&ky) kx++,ky--;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(sx==7||!sy) kx--,ky++;
                else sx++,sy--;
            }
        }
        else
        {
            if(kx&&ky) kx--,ky--;
            else continue;
            if(kx==sx&&ky==sy)
            {
                if(!sx||!sy) kx++,ky++;
                else sx--,sy--;
            }
        }
    }
    printf("%c%d\n%c%d\n",kx+'A',ky+1,sx+'A',sy+1);
    return 0;
}
