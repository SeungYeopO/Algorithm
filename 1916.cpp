#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
struct info {
	int to;
	int cost;
};
struct func_obj {
	bool operator()(info left, info right) {
		if (left.cost < right.cost)return false;
		if (left.cost > right.cost)return true;

		return false;
	}
};
vector<info>arr[100002];
int start, finish;
int dist[100002];
void dijkstra(int st, int fin) {
	for (int i = 0; i < 100002; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;
	priority_queue<info, vector<info>, func_obj> pq;
	pq.push({ st, 0 });

	while (!pq.empty()) {
		info now = pq.top(); pq.pop();
		int nowTo = now.to;
		int nowCost = now.cost;

		if (dist[nowTo] < nowCost) continue;

		for (int i = 0; i < arr[nowTo].size(); i++) {
			info next = arr[nowTo][i];
			int nextTo = arr[nowTo][i].to;
			int nextCost = arr[nowTo][i].cost;

			if (dist[nextTo] <= dist[nowTo] + nextCost) continue;

			dist[nextTo] = dist[nowTo] + nextCost;
			pq.push({ nextTo, dist[nextTo] });

		}
	}
	cout << dist[fin];

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
	}
	cin >> start >> finish;
	dijkstra(start, finish);

	return 0;
}