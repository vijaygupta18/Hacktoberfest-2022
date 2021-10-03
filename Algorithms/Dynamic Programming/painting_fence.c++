//Painting fence algorithm
#include <bits/stdc++.h>
using namespace std;
//no of ways
long count_Ways(int n, int k)
{
	long dp[n + 1];
	memset(dp, 0, sizeof(dp));
	long long mod = 1000000007;

	dp[1] = k;
	dp[2] = k * k;

	for (int i = 3; i <= n; i++) {
		dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
	}

	return dp[n];
}


int main()
{
	
	int n;
	cin>>n;
	int k;
	cin>>k;
	//n is the number of fences and k is the number of colors
	cout << count_Ways(n, k) << endl;
	return 0;
}
