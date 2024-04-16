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

	//while (left < N && right < N) { // <- 조건은 어떻게 주면 될까 ?
	//	if (sum < K) {
	//		right++; // 구간 넓히기
	//		sum += arr[right];
	//	}
	//	else if (sum > K) {
	//		sum -= arr[left];
	//		left++; // 구간 좁히기
	//	}
	//	else if (sum == K) {
	//		cout << "가능가능";
	//		return 0;
	//	} 
	//}
	//cout << "불가능" << endl;

	//연속된 4개의 합이 102
	int N, K;
	cin >> N >> K;
	int arr[100] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int left = 0;
	int right = 0;
	int sum = 0;

	while (left < N && right < N) { // <- 조건은 어떻게 주면 될까 ?
		if (right - left + 1 < 4) { // right - left + 1 : 구간의 개수
			right++; // data가 부족할때, 구간을 넓힘
			sum += arr[right];
		}
		else { // 
			sum -= arr[left];
			left++; // data가 충분, 구간을 옮길 때
		}

		if (sum == K) {
			cout << left << " to " << right << endl;
			return 0;
		}
	}
	cout << "불가능" << endl;


	return 0;
}