#include <iostream>

using namespace std;

int n, score;
int cnt = 0;
int level[102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> level[i];
	}
    for (int i = n - 1; i >= 1; i--) {
        while (level[i] <= level[i - 1]) {
            level[i - 1] -= 1;
            cnt++;
        }
    }

    cout << cnt;
}
