#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 7, 10, 14, 15, 56, 57, 64, 77, 99, 2727 };

	int k = 13;

	// �⺻
	// binary search�� �� �� '�� ���� ó������� �ϴ� �۾�' : *����*
	int left = 0;
	int right = 9;
	while (left<=right) { // ������ �������� ��������
		int mid = (left + right) / 2;
		// ������� ����

		if (arr[mid] > k) {			// mid���� �����ʿ� k�� ����
			right = mid - 1;		// right�� ���������� �Ű���
		}
		else if (arr[mid] < k) {	// mid���� ū�ʿ� k�� ����	
			left = mid + 1;			// left�� ū������ �Ű���
		}
		else if (arr[mid] == k) {
			cout << "find out !!";
		}
	}


	// upper_bound
	// arr���� k���� ū ���ڰ� ��� �����ϳ� ????
	int left = 0;
	int right = 0;
	int ret = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < k) {			// mid���� ū�ʿ� ����
			left = mid + 1;
		}
		else if (arr[mid] > k) {	// mid���� �����ʿ� ����
			ret = mid;
			right = mid - 1;

		}
	}
}