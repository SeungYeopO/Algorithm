#include<iostream>
#include<queue>

using namespace std;

struct Coord {
	int row;
	int col;

	bool operator<(Coord right) const {
		// '<' -> less
		// less는 MAX우선으로 나오는 구조
		// left < right의 결과 '참' : right가 먼저 나옴
		// left < right의 결과 '거짓' : left가 먼저 나옴

		// return true: right를 먼저 꺼낸다
		// return false: left를 먼저 꺼낸다

		// 1. row가 큰게 우선
		if (row < right.row) return true;
		if (row > right.row) return false;

		// 2. col이 작은게 우선
		if (col < right.col) return false;
		if (col > right.col) return true;

		// 3. 완전히 같은 경우면 무조건 false
		return false;
	}
};

struct func_obj {
	bool operator()(Coord left, Coord right) const {
		// 1. row가 큰게 우선
		if (left.row < right.row) return true;
		if (left.row > right.row) return false;

		// 2. col이 작은게 우선
		if (left.col < right.col) return false;
		if (left.col > right.col) return true;

		// 3. 완전히 같은 경우면 무조건 false
		return false;
	}
};

int main() {
	/*
	priority_queue<int, vector<int>, less<int>> pq;	
	// default: MAX 우선, 큰값부터 정렬해줌 <- less, operator<
	//			MIN 우선, 작은값부터 정렬해줌 <- greater

	//priority_queue.push(value): value를 priority_queue에 추가
	pq.push(6);
	pq.push(1);
	pq.push(7);
	pq.push(3);
	pq.push(2);
	pq.push(4);

	while (!pq.empty()) {
		int now = pq.top();	// priority_queue.top(): 우선순위가 가장 높은 data를 확인
		pq.pop();			// priority_queue.pop(): 우선순위가 가장 높은 data를 삭제 
		cout << now << " ";
	}
	*/

	priority_queue<Coord, vector<Coord>, func_obj> pq;

	pq.push({ 1,2 });
	pq.push({ 5,5});
	pq.push({ 5,4 });
	pq.push({ 1,3 });

	while (!pq.empty()) {
		Coord now = pq.top();	// priority_queue.top(): 우선순위가 가장 높은 data를 확인
		pq.pop();			// priority_queue.pop(): 우선순위가 가장 높은 data를 삭제 
		cout << now.row << " " << now.col << endl;
	}

	/*
	sort 
	=> 시간복잡도: NlogN
	=> 장점: 모든 data가 '정리', 중간번째 data를 찾기 용이
	=> 단점: 사용 도중에 data가 수정 및 추가, 삭제 불편

	priority queue
	=> 추가, 삭제: logN
	=> 단점: 우선순위가 가장 높은 data만 알 수 있음
			 중간에 있는 data를 수정할 시 -> '구조가 망가짐' 절대 하지마
	=> 장점: 사용 도중에 data가 추가, 삭제 용이함

	*/
	
	return 0;
}