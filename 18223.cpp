#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int node, line, p;
int from, to, cost;
struct info {
	int to;
	int cost;
};
vector<info>map[10002];
int dist[10002];
struct func_obj {
	bool operator() (info left, info right) {
		if (left.cost < right.cost) return false;
		if (left.cost > right.cost) return true;

		return false;
	}
};
vector<int>root;

int dijkstra(int st, int fin) {
	for (int i = 0; i < 10002; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;

	priority_queue<info, vector<info>, func_obj>pq;
	pq.push({ st, 0 });

	root.push_back(st);
	
	while (!pq.empty()) {
		info now = pq.top(); pq.pop();
		int nowTo = now.to;
		int nowCost = now.cost;

		if (dist[nowTo] < nowCost) continue;

		for (int i = 0; i < map[nowTo].size(); i++) {
			info next = map[nowTo][i];
			int nextTo = next.to;
			int nextCost = next.cost;

			if (dist[nextTo] <= dist[nowTo] + nextCost) {
				//root.pop_back();
				continue;
			}

			dist[nextTo] = dist[nowTo] + nextCost;
			
			pq.push({ nextTo, dist[nextTo] });
			//root.push_back(nextTo);
		}
	}

	//cout << dist[fin];

	return dist[fin];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> node >> line >> p;
	for (int i = 0; i < line; i++) {
		cin >> from >> to >> cost;
		map[from].push_back({ to, cost });
		map[to].push_back({ from, cost });
	}

	int pick = dijkstra(1, p) + dijkstra(p, node);
	int solo = dijkstra(1, node);

	if (solo < pick)
		cout << "GOOD BYE";
	else
		cout << "SAVE HIM";
	return 0;
}