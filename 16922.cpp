#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
//char rome[4] = { 'I', 'V', 'X', 'L' };
int rome[4] = { 1, 5, 10, 50 };
int tmp = 0;
vector<int> ans;
int arr[10001];
string str = "";

void dfs(int level, int idx) {
	if (level >= cnt) {
		arr[tmp]++;
		return;
	}
	else {
		for (int i = idx; i < 4; i++) {
			tmp += rome[i];
			dfs(level + 1, i);
			tmp -= rome[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> cnt;
	int fin = 0;
	dfs(0, 0);
	for (int i = 0; i < 10001; i++) {
		if (arr[i] > 0) {
			fin++;
		}
	}
	cout << fin;
}