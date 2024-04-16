#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
����
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
		//�Ÿ��� ª�� �� �켱, �Ÿ� ������������ ����
		if (left.cost < right.cost) return false;
		if (left.cost > right.cost) return true;

		return false;
	}
};

int cntNode, cntEdge;
vector<Edge> v[10];

void dikstra_1(int st) {
	int dist[10]; // DAT, index: �� ��ȣ, value: ���ݱ��� ����� �Ÿ�
	int isvalid[10] = { 0, }; // DAT, index: �� ��ȣ, value: �ش� ���� �Ÿ��� Ȯ���ΰ� ?

	for (int i = 0; i < 10; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;
	// -----����-----


	for (int j = 0; j < cntNode - 1; j++) {
		// � �켱������ ���� �� 1���� ����.
		// �Ÿ��� ª�� ��

		int minDist = 1e9;
		int minNode = -1;

		for (int node = 1; node <= cntNode; node++) {
			if (isvalid[node] == 0 && minDist > dist[node]) {
				// Ȯ��X && �Ÿ��� �ּ�
				minDist = dist[node];
				minNode = node;
			}
			// ���� ª�� �Ÿ��� �� 1��
		}
		isvalid[minNode] = 1;	// ���� ���� 'Ȯ��'

		// �̹��� Ȯ������ ������ �� �� �ִ� �� ã��
		int now = minNode;
		for (int i = 0; i < v[now].size(); i++) {
			Edge nextEdge = v[now][i];
			int next = v[now][i].to;
			int nextCost = v[now][i].cost;

			// 'now�� ���� next�� ���� �Ÿ�'�� �̹� �˰��ִ� ������� ��ȿ�����̸� ����
			if (dist[next] <= dist[now] + nextCost) { 
				continue;
			}

			// 'now�� ���� next�� ���� �Ÿ�'�� ������� best
			dist[next] = dist[now] + nextCost;
		}
	}
}

void dikstra_2(int st) {
	int dist[10]; // DAT, index: �� ��ȣ, value: ���ݱ��� ����� �Ÿ�
	int isvalid[10] = { 0, }; // DAT, index: �� ��ȣ, value: �ش� ���� �Ÿ��� Ȯ���ΰ� ?

	for (int i = 0; i < 10; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;
	// -----����-----

	priority_queue<Edge, vector<Edge>, func_obj> pq; // <- � �������� ���� ? (�Ÿ�, ���)
	pq.push({ 0, st }); // 0�� �Ÿ��� st��� ���� �� �� �ִ�.

	while(!pq.empty()){
		Edge nowEdge = pq.top(); 
		pq.pop();
		int now = nowEdge.to;
		int nowCost = nowEdge.cost;
		// ���� �̹� Ȯ���� ��(����� �Ϸ�� ��)�� �ٽ� ����ؾ� �ϴ� �۾��� ����
		if (dist[now] < nowCost) {
			// �ּ� �Ÿ��� dist[now]�� �̹��� ���� ������ nowCost���� �۴�
			// �̹� dist[now]�� �ش��ϴ� ������ ����� �Ϸ�
			continue;
		}	// <- �Ÿ��� �ּ��̸鼭 ó�� ����غ��� �� <- Ȯ�� �۾�


		// �̹��� Ȯ������ ������ �� �� �ִ� �� ã�� <= '��� ������ �� 1����'
		for (int i = 0; i < v[now].size(); i++) {
			Edge nextEdge = v[now][i];
			int next = v[now][i].to;
			int nextCost = v[now][i].cost;

			// 'now�� ���� next�� ���� �Ÿ�'�� �̹� �˰��ִ� ������� ��ȿ�����̸� ����
			if (dist[next] <= dist[now] + nextCost) {
				continue;
			}

			// 'now�� ���� next�� ���� �Ÿ�'�� ������� best
			dist[next] = dist[now] + nextCost;
			pq.push({ dist[next], next });
		}
	}
}

// dijkstr�� ����� �˰��� -> bfs
void dikstra_3(int st) {
	int dist[10];
	for (int i = 0; i < 10; i++) {
		dist[i] = 1e9;
	}
	dist[st] = 0;	

	priority_queue<Edge, vector<Edge>, func_obj> pq; // 2. queue ���� -> priority queue����
	pq.push({ 0, st }); // 3. ������ ����

	//7. pq�� �����������
	while (!pq.empty()) {
		Edge nowEdge = pq.top(); // 4. now ������
		pq.pop();
		int nowTo = nowEdge.to;
		int nowCost = nowEdge.cost;
		
		if (dist[nowTo] < nowCost) {
			continue;
		}

		// 5. now -> next�� ã��
		for (int i = 0; i < v[nowTo].size(); i++) {
			Edge nextEdge = v[nowTo][i];
			int nextTo = v[nowTo][i].to;
			int nextCost = v[nowTo][i].cost;

			if (dist[nextTo] <= dist[nowTo] + nextCost) {
				continue;
			}

			// 6. next�� pq�� �߰�
			dist[nextTo] = dist[nowTo] + nextCost;
			pq.push({ dist[nextTo], nextTo });
		}
	}
}

/*
��Ȯ�� ����

BFS
=> queue�� ���: 'ã�� �������' ������ ����
	-> ���� ������ ���� ��� ���� ���


Dijkstra
=> priority queue�� ���: '�Ÿ��� ª�� �������' ������ ����
	-> ���� ª�� �Ÿ��� ���� ���


������ ���� ������ BFS, ������ Dijkstra
1. ���� ������ ���� ��� ���� ��� ??? -> ���� ???
2. ���� ���ϸ� Dijkstra

*/

int main() {
	
	cin>> cntNode >> cntEdge;

	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost, to });
		v[to].push_back({ cost, from });
		// 1, �׷��� ����
	}
	return 0;
}