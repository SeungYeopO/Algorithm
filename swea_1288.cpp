#include <iostream>
#include <string>

using namespace std;

int t;
string n;
int dat[10];
int cnt = 1;

bool check(string num) {
	for (int i = 0; i < num.size(); i++) {
		dat[num[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (dat[i] == 0)
			return false;
		
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int num = stoi(n);
		while (!check(n)) {
			cnt++;
			int next = num * cnt;
			n = to_string(next);
		}
		cout << "#" << i << " " << n << endl;
		
		cnt = 1;
		for (int i = 0; i < 10; i++) {
			dat[i] = 0;
		}
	}
	return 0;
}