#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string str[20002];

int cmp(string before, string after) {
	if (before.length() == after.length())
		return before < after;
	else
		return before.length() < after.length();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];

	}
	sort(str, str + n, cmp);

	for (int i = 0; i < n; i++) {
		if (str[i] == str[i - 1]) continue;

		cout << str[i] << endl;
	}

	return 0;
}