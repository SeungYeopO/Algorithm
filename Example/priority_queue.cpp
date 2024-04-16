#include<iostream>
#include<queue>

using namespace std;

struct Coord {
	int row;
	int col;

	bool operator<(Coord right) const {
		// '<' -> less
		// less�� MAX�켱���� ������ ����
		// left < right�� ��� '��' : right�� ���� ����
		// left < right�� ��� '����' : left�� ���� ����

		// return true: right�� ���� ������
		// return false: left�� ���� ������

		// 1. row�� ū�� �켱
		if (row < right.row) return true;
		if (row > right.row) return false;

		// 2. col�� ������ �켱
		if (col < right.col) return false;
		if (col > right.col) return true;

		// 3. ������ ���� ���� ������ false
		return false;
	}
};

struct func_obj {
	bool operator()(Coord left, Coord right) const {
		// 1. row�� ū�� �켱
		if (left.row < right.row) return true;
		if (left.row > right.row) return false;

		// 2. col�� ������ �켱
		if (left.col < right.col) return false;
		if (left.col > right.col) return true;

		// 3. ������ ���� ���� ������ false
		return false;
	}
};

int main() {
	/*
	priority_queue<int, vector<int>, less<int>> pq;	
	// default: MAX �켱, ū������ �������� <- less, operator<
	//			MIN �켱, ���������� �������� <- greater

	//priority_queue.push(value): value�� priority_queue�� �߰�
	pq.push(6);
	pq.push(1);
	pq.push(7);
	pq.push(3);
	pq.push(2);
	pq.push(4);

	while (!pq.empty()) {
		int now = pq.top();	// priority_queue.top(): �켱������ ���� ���� data�� Ȯ��
		pq.pop();			// priority_queue.pop(): �켱������ ���� ���� data�� ���� 
		cout << now << " ";
	}
	*/

	priority_queue<Coord, vector<Coord>, func_obj> pq;

	pq.push({ 1,2 });
	pq.push({ 5,5});
	pq.push({ 5,4 });
	pq.push({ 1,3 });

	while (!pq.empty()) {
		Coord now = pq.top();	// priority_queue.top(): �켱������ ���� ���� data�� Ȯ��
		pq.pop();			// priority_queue.pop(): �켱������ ���� ���� data�� ���� 
		cout << now.row << " " << now.col << endl;
	}

	/*
	sort 
	=> �ð����⵵: NlogN
	=> ����: ��� data�� '����', �߰���° data�� ã�� ����
	=> ����: ��� ���߿� data�� ���� �� �߰�, ���� ����

	priority queue
	=> �߰�, ����: logN
	=> ����: �켱������ ���� ���� data�� �� �� ����
			 �߰��� �ִ� data�� ������ �� -> '������ ������' ���� ������
	=> ����: ��� ���߿� data�� �߰�, ���� ������

	*/
	
	return 0;
}