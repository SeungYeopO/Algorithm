#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, k;
struct info {
	int to;
	int cost;
};
vector<info>arr[300002];
int dist[300002];
struct func_obj {
	bool operator()(info left, info right) {
		if (left.cost < right.cost) return false;
		if (left.cost > right.cost) return true;

		return false;
	}
};

void dijkstra(int st) {
	for (int i = 0; i < 300002; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;

	priority_queue<info, vector<info>, func_obj>pq;
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

	for (int i = 1; i <= v; i++) {
		if (dist[i] != 1e9)
			cout << dist[i] << endl;
		else
			cout << "INF" << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	cin >> k;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
	}
	dijkstra(k);

	return 0;
}