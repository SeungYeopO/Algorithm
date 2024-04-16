#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 7, 10, 14, 15, 56, 57, 64, 77, 99, 2727 };

	int k = 13;

	// 기본
	// binary search를 할 때 '꼭 먼저 처리해줘야 하는 작업' : *정렬*
	int left = 0;
	int right = 9;
	while (left<=right) { // 구간이 뒤집히기 전까지만
		int mid = (left + right) / 2;
		// 정가운데를 가정

		if (arr[mid] > k) {			// mid보다 작은쪽에 k가 존재
			right = mid - 1;		// right를 작은쪽으로 옮겨줌
		}
		else if (arr[mid] < k) {	// mid보다 큰쪽에 k가 존재	
			left = mid + 1;			// left를 큰쪽으로 옮겨줌
		}
		else if (arr[mid] == k) {
			cout << "find out !!";
		}
	}


	// upper_bound
	// arr에서 k보다 큰 숫자가 어디서 시작하나 ????
	int left = 0;
	int right = 0;
	int ret = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < k) {			// mid보다 큰쪽에 있음
			left = mid + 1;
		}
		else if (arr[mid] > k) {	// mid보다 작은쪽에 있음
			ret = mid;
			right = mid - 1;

		}
	}
}