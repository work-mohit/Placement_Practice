#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x

typedef vector<int>	 vi;
typedef pair<int, int> pii;

#define ll long long
#define ld long double

#define all(a) (a).begin(), (a).end()

#define rep(i,n) for(int i=0;i<n;i++)
#define square(x) ((LL)(x) * (x))

#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int cost[31][31];
int dp[21][1 << 21];

int solve(int i , int mask, int& n) {
	if (mask == 0)
		return cost[i][0];

	if (dp[i][mask] != -1)
		return dp[i][mask];

	int ans = INT_MIN;
	for (int j = 0; j < n; j++) {
		ans = min(ans, cost[j][i] + solve(j, mask ^ (1 << j), n));
	}
	return dp[i][mask];

}

int main() {
	fast_io;
	int t;
	cin >> t;
	int n;
	memset(dp, -1, sizeof(dp));
	while (t--) {

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cost[i][j];
			}
		}
	}
	cout << solve(0, (1 << n) - 1, n);
	return 0;
}


