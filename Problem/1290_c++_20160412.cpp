#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> maze(n + 2, vector<int>(m + 2, 1));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '.')
				maze[i+1][j+1] = 0;
		}
	}
	vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n + 2, vector<vector<int>>(m + 2, vector<int>(2, 9)));
	dp[1][0][0] = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			dp[i][j][0] = min(dp[i][j - 1][0], dp[i][j - 1][1] + !maze[i + 1][j - 1]) + maze[i][j];
			dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + !maze[i - 1][j + 1]) + maze[i][j];
		}

	}

	cout << min(dp[n][m][0], dp[n][m][1]) << endl;

}
