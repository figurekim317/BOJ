#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 60010
#define M 100010

int n;
vector<int> a,b,c;

typedef complex<double> base;
void fft(vector <base> &a, bool invert)
{
    int n = (int)a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*3.14159265358979323846/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}

void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
{
    vector <base> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int n = 1;
    while (n < max((int)a.size(),(int)b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int main()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    a.resize(n<<1);
    b.resize(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]),a[i+n]=a[i];
    for(int i=n;i--;) scanf("%d",&b[i]);
    multiply(a,b,c);
    cout<<*max_element(&c[n],&c[n<<1]);
    return 0;
}
