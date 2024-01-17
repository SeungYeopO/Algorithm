#include<iostream>
#include<cstdio>

using namespace std;

int arr[11][11];
//map.
int check[11];
//도시를 방문 했는지 check
int n;
//n.
int m = 1e9;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int start, int y, int sum, int cnt) {
	if (cnt == n && start == y) {
		if (m > sum) m = sum;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (arr[y][x] == 0) continue;
		if (!check[y] && arr[y][x] > 0) {
			check[y] = true;
			sum += arr[y][x];
			if (sum <= m)
				dfs(start, x, sum, cnt + 1);
			check[y] = false;
			sum -= arr[y][x];
		}
	}
}
void solution() {
	for (int y = 0; y < n; y++) {
		dfs(y, y, 0, 0);
	}
}
void output() {
	cout << m << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	output();

	return 0;
}