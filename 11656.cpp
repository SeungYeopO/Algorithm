#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
vector<char>ans;
vector<string>dd;
string tmp = "";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--) {
		tmp += s[i];
		dd.push_back(tmp);
	}

	for (int i = 0; i < dd.size(); i++) {
		reverse(dd[i].begin(), dd[i].end());
	}
	sort(dd.begin(), dd.end());
	for (int i = 0; i < dd.size(); i++) {

		cout << dd[i] << endl;
	}
	return 0;
}