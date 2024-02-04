#include <iostream>
#include <queue>
#include <string>

using namespace std;

int m, n;
int map[1003][1003];
int visited[1003][1003];
queue<pair<int, int>>q;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool flag = 0;

bool func(int y, int x) {
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_y = now_y + dy[i];
			int new_x = now_x + dx[i];

			if (map[new_y][new_x]) continue;
			if (new_y < 0 || new_x < 0 || new_y >= m || new_x >= n) continue;
			if (visited[new_y][new_x]) continue;

			q.push({ new_y, new_x });
			visited[new_y][new_x] = visited[now_y][now_x] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (visited[m - 1][i] != 0)
			return true;
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	cin.ignore();
	string input;
	for (int i = 0; i < m; i++) {
		getline(cin, input);
		if (input.length() == n) {
			for (int j = 0; j < input.length(); j++) {
				map[i][j] = input[j] - '0';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!map[0][i]) {

			if (func(0, i))
				flag = 1;
			else
				flag = 0;
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}