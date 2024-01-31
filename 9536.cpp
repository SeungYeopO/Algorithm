#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int T;

int main()
{
	cin >> T;

	while (T--) {
		string buffer; //���� ����
		getline(cin, buffer);
		string origin; //�����Ҹ� ���
		getline(cin, origin);
		map<string, bool> m;
		while (true) {
			string a, b, c;
			cin >> a >> b >> c; //c�� �����Ҹ�
			if (a == "what") {
				cin >> b >> c; //fox say? ���� �Է��� �޴´�.
				break;
			}
			m[c] = true; //�����Ҹ� ���
		}

		string res = "";
		for (int i = 0; i < origin.size(); i++) {
			if (origin[i] == ' ') {
				if (!m[res])
					cout << res << " ";
				res = "";
			}
			else
				res += origin[i];
		}
		if (!m[res]) //�����Ҹ��� �������� Ȯ���Ѵ�.
			cout << res << " ";
		cout << "\n";
	}
}