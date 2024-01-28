#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int t;

int main() {
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++) {
		int N, M;
		cin >> N >> M;
		int lastNBit = (1 << N) - 1;  // 111...1 (±æÀÌ N)
		if (lastNBit == (M & lastNBit)) {
			cout << "#" << test_case << " " << "ON" << endl;
		}
		else {
			cout << "#" << test_case << " " << "OFF" << endl;
		}
	}

	return 0;
}
