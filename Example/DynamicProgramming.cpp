#include<iostream>
#include<algorithm>

using namespace std;

int map[7][3] = {
	{1,0,0},
	{1,2,2,},
	{0,3,0},
	{3,-10,-5},
	{15,-10,50},
	{15,-10,10},
	{0,6,4}
};
// dynamic programming : 계산했던것을 '기록'해서 기록이 있으면 다시 계산 X
int dp[7][3] = { 0 };
//dp[row][col]= row, col에서부터 몇점이 최대인가? <- 계산 결과

// 목표: dfs에서 '반환받으며' 계산

// 1. 기본적인 dfs구조 잡기
int dfs(int row,int col) {
	// 2. 함수 호출에 의미를 정확하게 부여
	// dfs(row, col): row, col으로 가라 !
	//		 upgrad : row, col에서부터 계산하면 몇이 최선이야 ??
	//				  row, col에서부터 최대 몇점까지 가능하냐 ??

	if (row >= 6) {		// 맨 마지막 층까지 내려가면 멈추기
		
		// 3. 맨 끝에서의 결과를 반환
		return map[row][col];
	}
	if (dp[row][col] != 0) {
		return dp[row][col];
	}
	int dr[] = { 1,1,1 };
	int dc[] = {-1,0,1 };
	int bestChoice = -1e9;

	for (int i = 0; i < 3; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (nr < 0 || nc < 0 || nr >= 7 || nc >= 3) continue;	// 맵을 벗어나면 무시
		if (map[nr][nc] == 0) continue;		// 벽을 만나면 무시
		
		int nextScore = dfs(nr, nc);	// <- next로 가라 !!
										// upgrade에서는 nr, nc부터는 최대 몇점인지 계산해와 !
		bestChoice = max(bestChoice, nextScore);	// next들 중 최대 점수 갱신
	}
	// next들 중 최대 점수에 내 점수를 더한게 내 최대 점수
	int nowScore = bestChoice + map[row][col];
	dp[row][col] = nowScore; // dp기록
	return nowScore;
}

void bottom_up() {
	int dp[7][3] = { 0 };	// 채워줄 배열
	dp[0][0] = map[0][0];	// 시작점 세팅
	for (int row = 1; row < 7; row++) {
		for (int col = 0; col < 3; col++) {
			// row, col에 대한 '시작점'부터 해당좌표까지의 최대 점수
			if (map[row][col] == 0) continue;
			// 바로 위 3좌표를 확인
			int dr[] = { 1,1,1 };
			int dc[] = { -1,0,1 };
			int bestChoice = -1e9;

			for (int i = 0; i < 3; i++) {
				int prevRow = row + dr[i];
				int prevCol = col + dc[i];
				bestChoice = max(bestChoice, dp[prevRow][prevCol]);
				if (prevRow < 0 || prevRow >= 7 || prevCol < 0 || prevRow >= 3) continue;
				if (map[prevRow][prevCol] == 0) continue;
			}
			dp[row][col] = bestChoice + map[row][col];
		}
	}
}

int main() {

	return 0;

}