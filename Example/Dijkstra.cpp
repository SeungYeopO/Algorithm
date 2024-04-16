#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
예제
8 10
from to cost
1 2 21
1 6 5
2 5 4
6 8 2
5 8 0
5 3 1
8 3 26
6 7 1004
7 4 6
3 4 7
*/

struct Edge {
	int cost;
	int to;
};

struct func_obj {
	bool operator()(Edge left, Edge right) const {
		//거리가 짧은 것 우선, 거리 오름차순으로 정렬
		if (left.cost < right.cost) return false;
		if (left.cost > right.cost) return true;

		return false;
	}
};

int cntNode, cntEdge;
vector<Edge> v[10];

void dikstra_1(int st) {
	int dist[10]; // DAT, index: 점 번호, value: 지금까지 계산한 거리
	int isvalid[10] = { 0, }; // DAT, index: 점 번호, value: 해당 점은 거리가 확정인가 ?

	for (int i = 0; i < 10; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;
	// -----세팅-----


	for (int j = 0; j < cntNode - 1; j++) {
		// 어떤 우선순위를 통해 점 1개를 고른다.
		// 거리가 짧은 점

		int minDist = 1e9;
		int minNode = -1;

		for (int node = 1; node <= cntNode; node++) {
			if (isvalid[node] == 0 && minDist > dist[node]) {
				// 확정X && 거리가 최소
				minDist = dist[node];
				minNode = node;
			}
			// 가장 짧은 거리인 점 1개
		}
		isvalid[minNode] = 1;	// 해장 점을 '확정'

		// 이번에 확정지은 점에서 갈 수 있는 점 찾기
		int now = minNode;
		for (int i = 0; i < v[now].size(); i++) {
			Edge nextEdge = v[now][i];
			int next = v[now][i].to;
			int nextCost = v[now][i].cost;

			// 'now를 통해 next로 가는 거리'가 이미 알고있던 방법보다 비효율적이면 무시
			if (dist[next] <= dist[now] + nextCost) { 
				continue;
			}

			// 'now를 통해 next로 가는 거리'가 현재까지 best
			dist[next] = dist[now] + nextCost;
		}
	}
}

void dikstra_2(int st) {
	int dist[10]; // DAT, index: 점 번호, value: 지금까지 계산한 거리
	int isvalid[10] = { 0, }; // DAT, index: 점 번호, value: 해당 점은 거리가 확정인가 ?

	for (int i = 0; i < 10; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;
	// -----세팅-----

	priority_queue<Edge, vector<Edge>, func_obj> pq; // <- 어떤 정보들을 저장 ? (거리, 노드)
	pq.push({ 0, st }); // 0의 거리로 st라는 점을 갈 수 있다.

	while(!pq.empty()){
		Edge nowEdge = pq.top(); 
		pq.pop();
		int now = nowEdge.to;
		int nowCost = nowEdge.cost;
		// 내가 이미 확정된 점(계산이 완료된 점)을 다시 계산해야 하는 작업을 방지
		if (dist[now] < nowCost) {
			// 최소 거리인 dist[now]가 이번에 꺼낸 정보인 nowCost보다 작다
			// 이미 dist[now]에 해당하는 정보로 계산이 완료
			continue;
		}	// <- 거리가 최소이면서 처음 계산해보는 점 <- 확정 작업


		// 이번에 확정지은 점에서 갈 수 있는 점 찾기 <= '모든 점에서 딱 1번씩'
		for (int i = 0; i < v[now].size(); i++) {
			Edge nextEdge = v[now][i];
			int next = v[now][i].to;
			int nextCost = v[now][i].cost;

			// 'now를 통해 next로 가는 거리'가 이미 알고있던 방법보다 비효율적이면 무시
			if (dist[next] <= dist[now] + nextCost) {
				continue;
			}

			// 'now를 통해 next로 가는 거리'가 현재까지 best
			dist[next] = dist[now] + nextCost;
			pq.push({ dist[next], next });
		}
	}
}

// dijkstr와 비슷한 알고리즘 -> bfs
void dikstra_3(int st) {
	int dist[10];
	for (int i = 0; i < 10; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;	

	priority_queue<Edge, vector<Edge>, func_obj> pq; // 2. queue 생성 -> priority queue생성
	pq.push({ 0, st }); // 3. 시작점 세팅

	//7. pq가 비워질때까지
	while (!pq.empty()) {
		Edge nowEdge = pq.top(); // 4. now 꺼내기
		pq.pop();
		int nowTo = nowEdge.to;
		int nowCost = nowEdge.cost;
		
		if (dist[nowTo] < nowCost) {
			continue;
		}

		// 5. now -> next를 찾기
		for (int i = 0; i < v[nowTo].size(); i++) {
			Edge nextEdge = v[nowTo][i];
			int nextTo = v[nowTo][i].to;
			int nextCost = v[nowTo][i].cost;

			if (dist[nextTo] <= dist[nowTo] + nextCost) {
				continue;
			}

			// 6. next를 pq에 추가
			dist[nextTo] = dist[nowTo] + nextCost;
			pq.push({ dist[nextTo], nextTo });
		}
	}
}

/*
정확한 차이

BFS
=> queue를 사용: '찾은 순서대로' 가보기 위해
	-> 적은 개수의 점을 들려 가는 방법


Dijkstra
=> priority queue를 사용: '거리가 짧은 순서대로' 가보기 위해
	-> 가장 짧은 거리로 가는 방법


문제에 따라 언제는 BFS, 언제는 Dijkstra
1. 적은 개수의 점을 들려 가는 방법 ??? -> 성립 ???
2. 성립 안하면 Dijkstra

*/

int main() {
	
	cin>> cntNode >> cntEdge;

	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost, to });
		v[to].push_back({ cost, from });
		// 1, 그래프 생성
	}
	return 0;
}