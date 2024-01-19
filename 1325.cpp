#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int>map[100002];
queue<int> q;
int visited[10002];
struct info {
	int index;
	int cnt;
};

vector<info>ans;
vector<int>fin;
int maxi = -1;
int cnt = 1;
int from, to;

int bfs(int st) {
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
	}

	visited[st] = true;
	q.push(st);
	cnt = 1;
	
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i];

			if (visited[next]) continue;
			
			visited[next] = true;
			cnt++;
			q.push(next);
			
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		
		cin >> to >> from;
		map[from].push_back(to);
	}

	for (int i = 1; i <= n; i++) {
		int tmp = bfs(i);
		maxi = max(tmp, maxi);
		ans.push_back({ i, tmp });
	}

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].cnt == maxi) {
			fin.push_back(ans[i].index);
		}
	}
	sort(fin.begin(), fin.end());
	for (int i = 0; i < fin.size(); i++) {
		cout << fin[i] << " ";
	}


	return 0;
}