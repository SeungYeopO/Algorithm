#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int t;
string s;
int dat[40];
vector<char>v;

void init() {
	v.clear();
	
	for (int i = 0; i < 40; i++) {
		dat[i] = 0;
	}
}

int check(string tmp) {
	init();

	int ans = -1;

	for (int i = 0; i < tmp.size(); i++) {
		if (dat[i] != ' ') {
			dat[tmp[i] - 'a']++;
		}
		
	}
	for (int i = 0; i < 40; i++) {
		ans = max(ans, dat[i]);
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin.ignore();
		getline(cin, s);
		
		//cout << s << endl;
		int res = check(s);

		for (int j = 0; j < 40; j++) {
			if (dat[j] == res) {
				v.push_back(j + 'a');
			}
		}

		if (v.size() > 1)
			cout << '?' << endl;
		else
			cout << v[0] << endl;


	}

	return 0;
}
