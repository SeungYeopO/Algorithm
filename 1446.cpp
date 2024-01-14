#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using namespace std;
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unordered_map<int, int> unmap;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		unmap.insert({ num, unmap[num]++ });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int idx;
		cin >> idx;
		cout << unmap[idx] << " ";
	}
	return 0;
}