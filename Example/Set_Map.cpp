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
	// it_set_begin < it_set_end; // �ε�ȣ�� �ȸ���.
	// it_set_begin + 3 // ���굵 �ȵ�.
	s.insert(1234);
	s.insert(777);
	s.insert(17);
	s.insert(24);
	s.insert(212);
	s.insert(5678);
	// �ߺ��Ǵ� data�� ������ ����. Ȥ�� �ߺ��ȴٸ� ���õ�

	//�⺻ ��ɾ�
	s.insert(111);	// �߰� <- logN
	s.find(111);	// ã�� <- logN
	s.erase(111);	// ���� <- logN
	s.clear();		// clear: data�� ���� ���� <- 1
	s.size();		// size: ���� �ִ� data ���� <- logN

	// ��� �����͸� Ȯ���ϰ� ���� ��� iterator�� ���
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it;
	}

	set<int>::iterator it_1234 = s.find(1234); // return : iterator
	set<int>::iterator it_9999 = s.find(9999); // find�� ���� data�� ã�ƴ޶� ?? -> iterator���� ���ٶ�� �ǹ�: end()

	s.erase(99999); // ���� ���� ������ ? -> �ƹ��ϵ� �Ͼ�� �ʴ´�.

	// s���� 3��°�� ������ ??
	auto it_3rd = s.begin();
	it_3rd++;
	it_3rd++;
	cout << *it_3rd;

	auto it_3rd = s.begin();
	it_3rd = next(it_3rd, 2);	// next(iterator, cnt) : iterator���� cnt��ŭ ������ iterator
								// next�� �ݴ�� prev : iterator���� cnt��ŭ ������ iterator
	cout << *it_3rd;
	// ���ĵ� �������� ���� ���� ��Ȳ
	// ��¥���� ����, �Ϸ翡 �Ѹ� ������ ����
	// �Ѵ޵����� ���� ��Ȳ
	set<int>reserveMonth;
	reserveMonth.insert(1);
	reserveMonth.insert(5);
	reserveMonth.insert(15);
	reserveMonth.insert(12);
	reserveMonth.insert(8);
	reserveMonth.insert(20);
	reserveMonth.insert(17);

	// A ~ B(Ư������ data)��� ��¥ ������ ���� ��Ȳ
	int A = 8;
	int B = 17;
	auto it_st = reserveMonth.lower_bound(A);	// A�̻��� '�����ϴ� ��ġ' -> ������ ok <- logN
	auto it_end = reserveMonth.upper_bound(B);	// B�ʰ��� '�����ϴ� ��ġ' -> ������ X <- logN
	for (auto it = it_st; it != it_end; it++) {
		cout << *it << "��\n";
	}


	//map

	map<int, int>m;	// map<key, value>���·� ����
	m.insert({ 90, 7 });
	m.insert({ 2, 77 });
	m.insert({ 4, 10 });
	m.insert({ 741, 166 });
	m.insert({ 789, 258 });
	m[10] = 951;	// m[10] <- 10�� key�� ���� �ִ°� ������ ���� ����, 
					// = 951 <- 951�� ����
	m[90] = 8;		// m[90] <- 90�� key�� ���� �ִ°� ������
					// = 8 <- �ű⿡ 8�� ����
	m.insert({ 10, 2123 }); // key�� 10�� �̹� ����: "����"
	
	// data�� ��� ���ñ� ??
	// key�� ���� ���ĵ� ������ ���´�.
	// map�� find�� set�� find�� �����ϰ� Ȱ�� <- key�� ���ؼ��� Ȯ��
	if (m.find(4) != m.end())
		cout << "4�� ����";
	else
		cout << "4�� ����";

	m.erase(10); // <- key�� ������� data�� ã�� ����

	// ��� data ã��
	for (auto it = m.begin(); it != m.end(); it++) {
		pair<int, int>p = *it;
		int key = p.first;
		int value = p.second;
		//cout << *it; // <- �� error�� �߻� ??
		cout << key << " " << value << endl;
	}

	// key�� data�� 1���� �ִ°� �ƴ� 2�� �̻� (ex. ��ǥ)
	struct Coord {
		int row;
		int col;
		bool operator<(Coord right) const {
			// ���ǻ��� !!!
			// struct���� Ȱ���ϴ� ��� data�� ���� �񱳱����� ���������
			if (row < right.row) return true;
			if (row > right.row) return false;

			if (col > right.col) return true;
			if (col < right.col) return false;

			return false;
		}
	};

	set<Coord>s;
	s.insert({ 1, 5 });







	// iterator �����ϱ� ���� ����
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	// -> vector �ȿ� �ִ� ��� data�� ���
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	for (int el : v) {	// python�� ����� ����
		// v�� �ִ� data���� �ϳ��ϳ� el�� ���� (���纻�� ���)
		cout << el;
	}

	// iterator <- ������ pointer�� ����� ��
	//sort(v.begin(), v.end());
	//v.begin();	// : v�� ���� ��ġ
	//v.end();	// : v�� �� ��ġ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		// pointer���� �� �ּҸ� ã�ư��� data�� �����Ͷ�
		cout << *it;
	}
	// auto: ���Կ����ڿ� �´� ������ �˾Ƽ� �����ض�
	for (auto it = v.begin(); it != v.end(); it++) {
		// pointer���� �� �ּҸ� ã�ư��� data�� �����Ͷ�
		cout << *it;
	}


	return 0;
}