#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[12][12];
int check[12][12];
int ans = -1e9;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool four_check(int y, int x) {
	for (int i = 0; i < 4; i++) {
		if (check[y + dy[i]][x + dx[i]] == 1)
			return false;
	}
	return true;
}
void func(int tot, int cnt) {
	if (cnt == k) {
		ans = max(tot, ans);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && four_check(i, j)) {
				check[i][j] = true;

				tot += arr[i][j];
				cnt++;
				func(tot, cnt);
				cnt--;
				tot -= arr[i][j];

				check[i][j] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0);

	cout << ans;
	return 0;

}