#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
	int cost;
	int to;
};
queue<int>q;
int dist[3] = { -1,1,0 };
int map[100002];
int visited[100002];
int n, m;

void init() {
	for (int i = 0; i < 100002; i++) {
		map[i] = 1e9;
	}
}

void bfs(int start, int finish) {
	q.push(start);
	map[start] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next;
			if (dist[i] == 0) {
				next = now * 2;
			}
			else {
				next = now + dist[i];
			}
			
			if (next < 0 || next > 100000) continue;
			if (map[next] < map[now] + 1) continue;

			q.push(next);
			map[next] = map[now] + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	init();
	bfs(n, m);

	cout << map[m];
	return 0;
}