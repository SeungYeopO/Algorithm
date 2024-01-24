#include <iostream>
#include <string>

using namespace std;

struct tim {
	int hour;
	int min;
	int sec;
};
string now_tim;
string bomb_tim;
string ans_tim;
char ans_sec[2];
char ans_min[2];
char ans_hour[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> now_tim;
	cin >> bomb_tim;
	tim now;
	now.hour = (now_tim[0] - '0') * 10 + (now_tim[1] - '0');
	now.min = (now_tim[3] - '0') * 10 + (now_tim[4] - '0');
	now.sec = (now_tim[6] - '0') * 10 + (now_tim[7] - '0');

	tim bomb;
	bomb.hour = (bomb_tim[0] - '0') * 10 + (bomb_tim[1] - '0');
	bomb.min = (bomb_tim[3] - '0') * 10 + (bomb_tim[4] - '0');
	bomb.sec = (bomb_tim[6] - '0') * 10 + (bomb_tim[7] - '0');

	tim ans;
	if (bomb.sec - now.sec < 0) {
		bomb.min -= 1;
		bomb.sec += 60;
	}
	ans.sec = bomb.sec - now.sec;
	if (bomb.min - now.min < 0) {
		bomb.hour -= 1;
		bomb.min += 60;
	}
	ans.min = bomb.min - now.min;
	if (bomb.hour - now.hour < 0) {
		bomb.hour += 24;
	}
	ans.hour = bomb.hour - now.hour;

	if (ans.hour == 0 && ans.min == 0 && ans.sec == 0)
		ans.hour += 24;

	ans_sec[0] = ans.sec / 10 + '0';
	ans_sec[1] = ans.sec % 10 + '0';

	ans_min[0] = ans.min / 10 + '0';
	ans_min[1] = ans.min % 10 + '0';

	ans_hour[0] = ans.hour / 10 + '0';
	ans_hour[1] = ans.hour % 10 + '0';

	cout << ans_hour[0] << ans_hour[1] 
		<< ":" << ans_min[0] << ans_min[1] 
		<< ":" << ans_sec[0] << ans_sec[1];

	return 0;
}