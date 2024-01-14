#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
using namespace std;
int n, m;
int num = 0;
vector<string>ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> unmap;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string listen;
		cin >> listen;
		unmap.insert({ listen, unmap[listen]++ });
	}
	for (int i = 0; i < m; i++) {
		string see;
		cin >> see;
		unmap.insert({ see, unmap[see]++ });
	}
	
	for (auto it = unmap.begin(); it != unmap.end(); it++) {
		if ((*it).second > 1) {
			num++;
			ans.push_back((*it).first);
		}
	}
	cout << num << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}