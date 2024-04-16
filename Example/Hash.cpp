#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Node {
	int row;
	int col;
	bool operator==(Node right) const {	// 같은 hashValue에서 정확한 key의 data를 찾기 위해 사용
		return row == right.row && col == right.col;
	}
};
struct HashFunction_return1 {	// function object
	size_t operator()(int key) const { // <- const 이 함수에서는 함수 바깥의 다른 data를 수정하지 않겠다. 원본을 수정하지 않겠다.

		return 1;
	}
};
struct HashFuncNode {
	size_t operator() (Node key) const {
		return key.row * 10000 + key.col;
		// ex) row: 987, col: 132
		// => 9870123, hashvalue 충돌 방지하기 위해
	}
};
int main() {

	unordered_map<int, Node>um;
	// data 추가
	um.insert({ 1, {5, 3} }); // 1 -> 5,3
	um.insert({ 5678, {12, 9} });
	um.insert({ 9, {21, 4} });
	um.insert({ 7, {8, 9753} });
	um.insert({ 0, {1910, 32} });
	//um.insert({ -2134567890, {21434567890, 123456798} });

	// data 수정 or 추가
	// ex) 1번 점의 좌표를 951, 7753으로 바꾸고 싶다.
	um[1] = { 951, 7753 };	// <- 이미 있는 key라서 해당 key의 value를 수정
	um[123] = { 987, 4 };	// <- 없는 key로 사용 ? ==> 추가된다.

	if (um[-1].row == 0 && um[-1].col == 0) // <- key: -1로 data가 추가
		cout << "1";
	
	// data 삭제
	um.erase(-1);	// 해당 key의 data 삭제

	// data 찾기
	// 특정 key의 iterator 가져오기
	auto it_minus = um.find(-2134567890);
	// 응용: 특정 key가 존재 ??
	if (um.find(1) == um.end())
		cout << "찾지 못함";
	else
		cout << "찾음";

	// 모든 data 출력
	for (auto it = um.begin(); it != um.end(); it++) {
		cout << "key: " << (*it).first << endl;
		cout << "value: " << (*it).second.row << " " << (*it).second.col << endl;
	}

	map<string, int>maap;
	// 디버깅 시 map은 value만 나옴
	maap.insert({ "one", 951 });
	maap.insert({ "two", 123 });
	maap.insert({ "nine", 753 });
	maap.insert({ "none", 32 });
	maap.insert({ "lucky", 777 });
	

	unordered_map<string, int>unmaap;
	// 디버깅 시 unordered_map은 key,value쌍이 나옴
	unmaap.insert({ "one", 951 });
	unmaap.insert({ "two", 123 });
	unmaap.insert({ "nine", 753 });
	unmaap.insert({ "none", 32 });
	unmaap.insert({ "lucky", 777 });
	

	unordered_set<string> unset;
	// 추가
	unset.insert("ssafy");
	unset.insert("null");
	unset.insert("to insert");
	unset.insert("value is string");

	// 삭제
	unset.erase("null");

	// 찾기
	auto it_string = unset.find("ssafy");
	cout << *it_string;

	// 모든 data 출력
	for (auto it = unset.begin(); it != unset.end(); it++) {
		cout << *it << endl;
	}

	unordered_map<int, int> hashValue_origin;
	unordered_map<int, int, HashFunction_return1> hashValue_1;

	cout << "origin start" << endl;
	for (int i = 0; i < 100000; i++) {
		hashValue_origin[i] = i;
	}
	cout << "origin end" << endl;

	cout << "return1 start" << endl;
	for (int i = 0; i < 100000; i++) {
		hashValue_1[i] = i;	// 시간이 엄청 걸리게 된다. 충돌이 일어나기 때문.
	}
	cout << "return1 end" << endl;

	unordered_map<Node, int, HashFuncNode> coordNum;
	coordNum.insert({ { 5, 3 }, 7 });
	coordNum.insert({ { 1, 7 }, 6 });
	coordNum.insert({ { 8, 5 }, 4 });
	coordNum.insert({ { 3, 5 }, -1 });

	return 0;
}