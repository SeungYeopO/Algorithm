#include <iostream>
#include <algorithm>
using namespace std;

// KrusKal 알고리즘
// 1. Edge를 저장
// 2. Edge를 정렬
// 3. Edge를 순서대로 연결 -> 이미 연결된 점끼린 연결 X

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
//		// 1. Edge 저장
//	}
//
//	// 2. Edge 정렬
//	sort(edges, edges + cntEdge); // cost 기준으로 오름차순 정렬
//	
//	// 번외 1. parent 초기화
//	for (int i = 1; i <= cntNode; i++) {
//		parent[i] = i;
//	}
//
//	int sum = 0;
//	// 3. Edge 연결 -> Union Find
//	for (int i = 0; i < cntEdge; i++) {
//		Edge now = edges[i];
//
//		// 이미 같은 그룹(연결)이면 무시
//		if (Find(now.A) == Find(now.B)) continue;
//
//		Union(now.A, now.B); // 실제 연결
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