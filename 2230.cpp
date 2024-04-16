#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int>arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	int left = 0;
	int right = 0;
	int sub = 0;
	int ans = 10e9;
	while (left < N &&right < N) {
		sub = abs(arr[left] - arr[right]);
		
		if (sub < M) {
			right++;
		}
		else if (sub >= M) {
			left++;
			ans = min(sub, ans);
		}

	}
	cout << ans;
}