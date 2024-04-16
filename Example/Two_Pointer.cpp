#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//int N, K;
	//cin >> N >> K;
	//int arr[100] = { 0, };
	//for (int i = 0; i < 100; i++) {
	//	cin >> arr[i];
	//}
	//int left = 0;
	//int right = 0;
	//int sum = arr[0];

	//while (left < N && right < N) { // <- ������ ��� �ָ� �ɱ� ?
	//	if (sum < K) {
	//		right++; // ���� ������
	//		sum += arr[right];
	//	}
	//	else if (sum > K) {
	//		sum -= arr[left];
	//		left++; // ���� ������
	//	}
	//	else if (sum == K) {
	//		cout << "���ɰ���";
	//		return 0;
	//	} 
	//}
	//cout << "�Ұ���" << endl;

	//���ӵ� 4���� ���� 102
	int N, K;
	cin >> N >> K;
	int arr[100] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int left = 0;
	int right = 0;
	int sum = 0;

	while (left < N && right < N) { // <- ������ ��� �ָ� �ɱ� ?
		if (right - left + 1 < 4) { // right - left + 1 : ������ ����
			right++; // data�� �����Ҷ�, ������ ����
			sum += arr[right];
		}
		else { // 
			sum -= arr[left];
			left++; // data�� ���, ������ �ű� ��
		}

		if (sum == K) {
			cout << left << " to " << right << endl;
			return 0;
		}
	}
	cout << "�Ұ���" << endl;


	return 0;
}