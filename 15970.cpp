#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int point, color;
struct info {
	int point;
	int color;
};
vector<info> arr;
int fin = 0;

int check(int nowPoint, int nowColor) {
	
	int len=1e9;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].point != nowPoint && arr[i].color == nowColor) {
			len = min(abs(nowPoint - arr[i].point), len);
		}
	}
	return len;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> point >> color;
		info tmp;
		tmp.point = point;
		tmp.color = color;
		arr.push_back(tmp);
	}
	for (int i = 0; i < arr.size(); i++) {
		int ans = check(arr[i].point, arr[i].color);
		fin += ans;
	}
	
	cout << fin;
	return 0;
}