#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int m, n;
int primeNum[10002];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	primeNum[0] = 1;
	primeNum[1] = 1;

	cin >> m >> n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (primeNum[i] == 0) {
			for (int j = i + i; j <= n; j+=i) {
				primeNum[j] = 1;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (!primeNum[i]) {
			ans.push_back(i);
		}
	}

	int fin = 0;
	if (!ans.empty()) {
		for (int i = 0; i < ans.size(); i++) {
			fin += ans[i];
		}

		cout << fin << endl;
		cout << ans[0];
	}
	else {
		cout << -1;
	}

	return 0;
}