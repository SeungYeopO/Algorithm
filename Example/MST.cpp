#include <iostream>
#include <algorithm>
using namespace std;

// KrusKal �˰���
// 1. Edge�� ����
// 2. Edge�� ����
// 3. Edge�� ������� ���� -> �̹� ����� ������ ���� X

//struct Edge {
//	int cost;
//	int A, B;
//	bool operator< (Edge right) {
//		if (cost < right.cost) return true;
//		if (cost > right.cost) return false;
//
//		if (A < right.A) return true;
//		if (A > right.A) return false;
//
//		if (B < right.B) return true;
//		if (B > right.B) return false;
//
//		return false;
//	}
//};
//Edge edges[20];
//int parent[20];
//
//int Find(int A) {
//	if (A == parent[A]) return A;
//	return parent[A] = Find(parent[A]);
//}
//void Union(int A, int B) {
//	int rootA = Find(A);
//	int rootB = Find(B);
//	parent[rootA] = rootB;
//}
//
//int main(void) {
//	int cntNode, cntEdge;
//	cin >> cntNode >> cntEdge;
//
//	for (int i = 0; i < cntEdge; i++) {
//		int A, B, cost;
//		cin >> A >> B >> cost;
//		edges[i] = { cost, A, B };
//		// 1. Edge ����
//	}
//
//	// 2. Edge ����
//	sort(edges, edges + cntEdge); // cost �������� �������� ����
//	
//	// ���� 1. parent �ʱ�ȭ
//	for (int i = 1; i <= cntNode; i++) {
//		parent[i] = i;
//	}
//
//	int sum = 0;
//	// 3. Edge ���� -> Union Find
//	for (int i = 0; i < cntEdge; i++) {
//		Edge now = edges[i];
//
//		// �̹� ���� �׷�(����)�̸� ����
//		if (Find(now.A) == Find(now.B)) continue;
//
//		Union(now.A, now.B); // ���� ����
//		sum += now.cost;
//	}
//	cout << sum;
//
//	return 0;
//}

int main(void) {
	int cntNode, cntEdge;
	cin >> cntNode >> cntEdge;
	for (int i = 0; i < cntEdge; i++) {
		int A, B, cost;
		cin >> A >> B >> cost;


	}
	
	
	return 0;
}