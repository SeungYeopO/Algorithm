#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int num;
char input;
string arr;
stack<char> open_st;
stack<char> close_st;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr;
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] == '(') {
				open_st.push(arr[i]);

			}

			else if (arr[i] == ')') {
				if (!open_st.empty()) {
					open_st.pop();
				}
				else if (open_st.empty()) {
					close_st.push(arr[i]);
				}
					
			}

		}
		if (open_st.empty() && close_st.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
		while (!open_st.empty())
			open_st.pop();
		while (!close_st.empty())
			close_st.pop();
	}	

	return 0;
}