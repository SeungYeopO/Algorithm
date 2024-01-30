#include <iostream>
#include <queue>
using namespace std;

int t, m, n, k;
int map[52][52];
int visited[52][52];
queue<pair<int, int>>q;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {

	visited[y][x] = true;
	q.push({ y, x });


	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + dy[i];
			int next_x = now_x + dx[i];

			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) continue;
			if (visited[next_y][next_x]) continue;
			if (map[next_y][next_x] == 0) continue;

			visited[next_y][next_x] = true;
			q.push({ next_y, next_x });
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
	}


	return 0;
}