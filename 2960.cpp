#include <iostream>
#include <vector>

using namespace std;

int n, k;
int number = 1002;
int primeNum[1002];
vector<int> ans;
vector<int> fin;
int dat[1002];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		primeNum[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (primeNum[i] == 0)
			continue;
		//ans.push_back(i);
		for (int j = i; j <= n; j += i) {
			primeNum[j] = 0;
			ans.push_back(j);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		if (!dat[ans[i]]) {
			fin.push_back(ans[i]);
			dat[ans[i]]++;
		}
			
	}

	cout << fin[k - 1];


	return 0;
}