#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, K, answer = -1;
vector<int> v(N);
int visited[100002];

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) cin >> v[i];

	int en = 0;
	int st = 0;
	for (int st = 0; st < N; st++) {
		while (en < N && visited[v[en]] < K) {
			visited[v[en]]++;
			en++;
		}
		answer = max(answer, en - st);
		if (en == N) break;
		visited[v[st]]--;
	}
	cout << answer << endl;

	return 0;
}