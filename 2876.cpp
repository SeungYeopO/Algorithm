#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[52][52];
int visited[52][52];
int h, w;
queue<pair<int, int>>q;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int cnt = 0;
vector<int>ans;

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = 0;
		}
	}

	cnt = 0;
}
void bfs(int y, int x) {
	visited[y][x] = 1;
	q.push({ y,x });

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		
		q.pop();

		for (int i = 0; i < 8; i++) {
			int new_y = cur_y + dy[i];
			int new_x = cur_x + dx[i];

			if (new_y < 0 || new_x < 0 || new_y >= h || new_x >= w)
				continue;
			if (visited[new_y][new_x] == 1)
				continue;
			if (map[new_y][new_x] == 0)
				continue;

			visited[new_y][new_x] = 1;
			q.push({ new_y, new_x });
		}
	}
 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		init();
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
					

			}
		}
		ans.push_back(cnt);
		//cut << cnt <<endl;

	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}