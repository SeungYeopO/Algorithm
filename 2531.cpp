#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, d, k, c;
int dat[3333];
int ans = 0;
int tmp;
vector<int>vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	for (int i = 0; i < k; i++) {
		vec.push_back(vec[i]);
	}

	int left;
	int right;
	int cnt;
	
	for (int i = 0; i < n; i++) {
		left = i;
		right = left + k;
		cnt = 0;

		for (int j = left; j < right; j++) {
			if (!dat[vec[j]]) {
				dat[vec[j]]++;
				cnt++;
			}
		}
		if (!dat[c]) {
			cnt++;
		}

		ans = max(ans, cnt);

		for (int j = 0; j < 3333; j++) {
			dat[j] = 0;
		}
	}
	
	cout << ans;

	return 0;
}