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
// dynamic programming : ����ߴ����� '���'�ؼ� ����� ������ �ٽ� ��� X
int dp[7][3] = { 0 };
//dp[row][col]= row, col�������� ������ �ִ��ΰ�? <- ��� ���

// ��ǥ: dfs���� '��ȯ������' ���

// 1. �⺻���� dfs���� ���
int dfs(int row,int col) {
	// 2. �Լ� ȣ�⿡ �ǹ̸� ��Ȯ�ϰ� �ο�
	// dfs(row, col): row, col���� ���� !
	//		 upgrad : row, col�������� ����ϸ� ���� �ּ��̾� ??
	//				  row, col�������� �ִ� �������� �����ϳ� ??

	if (row >= 6) {		// �� ������ ������ �������� ���߱�
		
		// 3. �� �������� ����� ��ȯ
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

		if (nr < 0 || nc < 0 || nr >= 7 || nc >= 3) continue;	// ���� ����� ����
		if (map[nr][nc] == 0) continue;		// ���� ������ ����
		
		int nextScore = dfs(nr, nc);	// <- next�� ���� !!
										// upgrade������ nr, nc���ʹ� �ִ� �������� ����ؿ� !
		bestChoice = max(bestChoice, nextScore);	// next�� �� �ִ� ���� ����
	}
	// next�� �� �ִ� ������ �� ������ ���Ѱ� �� �ִ� ����
	int nowScore = bestChoice + map[row][col];
	dp[row][col] = nowScore; // dp���
	return nowScore;
}

void bottom_up() {
	int dp[7][3] = { 0 };	// ä���� �迭
	dp[0][0] = map[0][0];	// ������ ����
	for (int row = 1; row < 7; row++) {
		for (int col = 0; col < 3; col++) {
			// row, col�� ���� '������'���� �ش���ǥ������ �ִ� ����
			if (map[row][col] == 0) continue;
			// �ٷ� �� 3��ǥ�� Ȯ��
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