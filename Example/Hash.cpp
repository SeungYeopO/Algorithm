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
	bool operator==(Node right) const {	// ���� hashValue���� ��Ȯ�� key�� data�� ã�� ���� ���
		return row == right.row && col == right.col;
	}
};
struct HashFunction_return1 {	// function object
	size_t operator()(int key) const { // <- const �� �Լ������� �Լ� �ٱ��� �ٸ� data�� �������� �ʰڴ�. ������ �������� �ʰڴ�.

		return 1;
	}
};
struct HashFuncNode {
	size_t operator() (Node key) const {
		return key.row * 10000 + key.col;
		// ex) row: 987, col: 132
		// => 9870123, hashvalue �浹 �����ϱ� ����
	}
};
int main() {

	unordered_map<int, Node>um;
	// data �߰�
	um.insert({ 1, {5, 3} }); // 1 -> 5,3
	um.insert({ 5678, {12, 9} });
	um.insert({ 9, {21, 4} });
	um.insert({ 7, {8, 9753} });
	um.insert({ 0, {1910, 32} });
	//um.insert({ -2134567890, {21434567890, 123456798} });

	// data ���� or �߰�
	// ex) 1�� ���� ��ǥ�� 951, 7753���� �ٲٰ� �ʹ�.
	um[1] = { 951, 7753 };	// <- �̹� �ִ� key�� �ش� key�� value�� ����
	um[123] = { 987, 4 };	// <- ���� key�� ��� ? ==> �߰��ȴ�.

	if (um[-1].row == 0 && um[-1].col == 0) // <- key: -1�� data�� �߰�
		cout << "1";
	
	// data ����
	um.erase(-1);	// �ش� key�� data ����

	// data ã��
	// Ư�� key�� iterator ��������
	auto it_minus = um.find(-2134567890);
	// ����: Ư�� key�� ���� ??
	if (um.find(1) == um.end())
		cout << "ã�� ����";
	else
		cout << "ã��";

	// ��� data ���
	for (auto it = um.begin(); it != um.end(); it++) {
		cout << "key: " << (*it).first << endl;
		cout << "value: " << (*it).second.row << " " << (*it).second.col << endl;
	}

	map<string, int>maap;
	// ����� �� map�� value�� ����
	maap.insert({ "one", 951 });
	maap.insert({ "two", 123 });
	maap.insert({ "nine", 753 });
	maap.insert({ "none", 32 });
	maap.insert({ "lucky", 777 });
	

	unordered_map<string, int>unmaap;
	// ����� �� unordered_map�� key,value���� ����
	unmaap.insert({ "one", 951 });
	unmaap.insert({ "two", 123 });
	unmaap.insert({ "nine", 753 });
	unmaap.insert({ "none", 32 });
	unmaap.insert({ "lucky", 777 });
	

	unordered_set<string> unset;
	// �߰�
	unset.insert("ssafy");
	unset.insert("null");
	unset.insert("to insert");
	unset.insert("value is string");

	// ����
	unset.erase("null");

	// ã��
	auto it_string = unset.find("ssafy");
	cout << *it_string;

	// ��� data ���
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
		hashValue_1[i] = i;	// �ð��� ��û �ɸ��� �ȴ�. �浹�� �Ͼ�� ����.
	}
	cout << "return1 end" << endl;

	unordered_map<Node, int, HashFuncNode> coordNum;
	coordNum.insert({ { 5, 3 }, 7 });
	coordNum.insert({ { 1, 7 }, 6 });
	coordNum.insert({ { 8, 5 }, 4 });
	coordNum.insert({ { 3, 5 }, -1 });

	return 0;
}