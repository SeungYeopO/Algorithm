#include <iostream>
#include <vector>
#include <map> 
#include <set>
#include <algorithm>
using namespace std;

int main() {

	//set

	set<int> s;

	auto it_set_begin = s.begin();
	auto it_set_end = s.end();
	// it_set_begin < it_set_end; // 부등호과 안먹힘.
	// it_set_begin + 3 // 연산도 안됨.
	s.insert(1234);
	s.insert(777);
	s.insert(17);
	s.insert(24);
	s.insert(212);
	s.insert(5678);
	// 중복되는 data는 허용되지 않음. 혹시 중복된다면 무시됨

	//기본 명령어
	s.insert(111);	// 추가 <- logN
	s.find(111);	// 찾기 <- logN
	s.erase(111);	// 삭제 <- logN
	s.clear();		// clear: data를 전부 삭제 <- 1
	s.size();		// size: 갖고 있는 data 개수 <- logN

	// 모든 데이터를 확인하고 싶은 경우 iterator를 사용
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it;
	}

	set<int>::iterator it_1234 = s.find(1234); // return : iterator
	set<int>::iterator it_9999 = s.find(9999); // find로 없는 data를 찾아달라 ?? -> iterator에서 없다라는 의미: end()

	s.erase(99999); // 없는 수를 지워라 ? -> 아무일도 일어나지 않는다.

	// s에서 3번째로 작은수 ??
	auto it_3rd = s.begin();
	it_3rd++;
	it_3rd++;
	cout << *it_3rd;

	auto it_3rd = s.begin();
	it_3rd = next(it_3rd, 2);	// next(iterator, cnt) : iterator에서 cnt만큼 다음의 iterator
								// next의 반대는 prev : iterator에서 cnt만큼 이전의 iterator
	cout << *it_3rd;
	// 정렬된 구조에서 많이 쓰는 상황
	// 날짜별로 예약, 하루에 한명만 예약이 가능
	// 한달동안의 예약 현황
	set<int>reserveMonth;
	reserveMonth.insert(1);
	reserveMonth.insert(5);
	reserveMonth.insert(15);
	reserveMonth.insert(12);
	reserveMonth.insert(8);
	reserveMonth.insert(20);
	reserveMonth.insert(17);

	// A ~ B(특정구간 data)라는 날짜 사이의 예약 현황
	int A = 8;
	int B = 17;
	auto it_st = reserveMonth.lower_bound(A);	// A이상이 '시작하는 위치' -> 어디부터 ok <- logN
	auto it_end = reserveMonth.upper_bound(B);	// B초과가 '시작하는 위치' -> 어디부터 X <- logN
	for (auto it = it_st; it != it_end; it++) {
		cout << *it << "일\n";
	}


	//map

	map<int, int>m;	// map<key, value>형태로 관리
	m.insert({ 90, 7 });
	m.insert({ 2, 77 });
	m.insert({ 4, 10 });
	m.insert({ 741, 166 });
	m.insert({ 789, 258 });
	m[10] = 951;	// m[10] <- 10을 key로 갖고 있는게 없으면 새로 생성, 
					// = 951 <- 951을 저장
	m[90] = 8;		// m[90] <- 90을 key로 갖고 있는게 있으면
					// = 8 <- 거기에 8을 저장
	m.insert({ 10, 2123 }); // key로 10이 이미 존재: "무시"
	
	// data가 어떻게 나올까 ??
	// key에 대해 정렬된 순서로 나온다.
	// map의 find는 set의 find와 동일하게 활용 <- key에 대해서만 확인
	if (m.find(4) != m.end())
		cout << "4가 존재";
	else
		cout << "4가 없음";

	m.erase(10); // <- key를 기반으로 data를 찾아 삭제

	// 모든 data 찾기
	for (auto it = m.begin(); it != m.end(); it++) {
		pair<int, int>p = *it;
		int key = p.first;
		int value = p.second;
		//cout << *it; // <- 왜 error가 발생 ??
		cout << key << " " << value << endl;
	}

	// key로 data를 1개만 넣는게 아닌 2개 이상 (ex. 좌표)
	struct Coord {
		int row;
		int col;
		bool operator<(Coord right) const {
			// 주의사항 !!!
			// struct에서 활용하는 모든 data에 대해 비교기준을 세워줘야함
			if (row < right.row) return true;
			if (row > right.row) return false;

			if (col > right.col) return true;
			if (col < right.col) return false;

			return false;
		}
	};

	set<Coord>s;
	s.insert({ 1, 5 });







	// iterator 설명하기 위한 예시
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	// -> vector 안에 있는 모든 data를 출력
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	for (int el : v) {	// python과 비슷한 구문
		// v에 있는 data들을 하나하나 el에 저장 (복사본을 사용)
		cout << el;
	}

	// iterator <- 일종의 pointer와 비슷한 것
	//sort(v.begin(), v.end());
	//v.begin();	// : v의 시작 위치
	//v.end();	// : v의 끝 위치
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		// pointer에서 그 주소를 찾아가서 data를 가져와라
		cout << *it;
	}
	// auto: 대입연산자에 맞는 구조로 알아서 설정해라
	for (auto it = v.begin(); it != v.end(); it++) {
		// pointer에서 그 주소를 찾아가서 data를 가져와라
		cout << *it;
	}


	return 0;
}