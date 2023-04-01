#include<bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000;
int n, dp[100][100];

int count(int left, int right){
	if(left + right == 0) return 1;
	int &ret = dp[left][right];
	if(ret != -1) return ret;

	ret = 0;
	if(right == 0) return ret;
	for(int i=0; i<right; i++)
		ret += count(right-1-i, left+i) % MOD;
	return ret % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if(n==1){
		cout << 1;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for(int i=0; i<n; ++i){
		ans += count(i, n-i-1) % MOD;
		ans += count(n-i-1, i) % MOD;
	}
	cout << ans % MOD;
}
