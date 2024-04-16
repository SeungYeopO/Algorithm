#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N;
int map[31][31];
int visited[31][31];
queue<pair<int, int>>q;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int dat[666];
string str;

void bfs(int y, int x, int num) {
	int cnt = 1;
	q.push({ y, x });
	visited[y][x] = num;
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= N) continue;
			if (map[next_y][next_x] == 0) continue;
			if (visited[next_y][next_x]) continue;

			q.push({ next_y, next_x });
			visited[next_y][next_x] = num;
			++cnt;
		}
	}
	dat[num] = cnt;

	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j] - '0';
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0 && visited[i][j] == 0) {
				cnt++;
				bfs(i, j, cnt);
				
			}

		}
	}

	cout << cnt << endl;
	sort(dat, dat + 666);

	for (int i = 0; i < 666; i++) {
		if (dat[i] > 0) {
			cout << dat[i] << endl;
		}
	}
	

	return 0;
}
