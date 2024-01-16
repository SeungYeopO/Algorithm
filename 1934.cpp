#include <iostream>

using namespace std;

int gcd(int num1, int num2) {
	while (num2 > 0) {
		int tmp = num1;
		num1 = num2;
		num2 = tmp % num2;
	}

	return num1;
}

int calc(int num1, int num2) {
	return num1 * num2 / gcd(num1, num2);
}

int n, a, b, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b) {
			ans = calc(a, b);
		}
		else {
			ans = calc(b, a);
		}
		cout << ans << endl;
	}

	

}