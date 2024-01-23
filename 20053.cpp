#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, num;
vector<int>arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());

		cout << arr[0] << " " << arr[n - 1] << endl;
		arr.clear();
	}
	return 0;
	
}