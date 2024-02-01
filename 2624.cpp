#include <iostream>
#include <utility>
using namespace std;

pair<int, int> coins[101];
int T, k;
int d[10001][101];

int Dp(int sum, int idx) {
	if (sum == 0) return d[sum][idx] = 1;
	if (idx > k) return d[sum][idx] = 0;

	if (d[sum][idx] != -1) return d[sum][idx];

	int result = 0;

	for (int i = 0; i <= coins[idx].second; i++) {
		if (sum - (coins[idx].first*i) >= 0)
			result += Dp(sum - (coins[idx].first*i), idx + 1);
	}
	return d[sum][idx] = result;
}
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> T >> k;

	for (int i = 0; i < 10001; i++)
		for (int j = 1; j < 101; j++) d[i][j] = -1;
	for (int i = 1; i <= k; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		coins[i] = make_pair(v1, v2);
	}
	cout << Dp(T, 1);
}