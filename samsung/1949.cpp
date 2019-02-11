#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int n, k, arr[10][10], visit[10][10], chk;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void dfs(int a, int b, int c, int d) {
	chk = max(d, chk);
	int kx, ky;
	for (int i = 0; i < 4; i++) {
		kx = a + dx[i];
		ky = b + dy[i];
		if (kx >= 0 && kx < n && ky >= 0 && ky < n) {
			if (arr[a][b] > arr[kx][ky] && visit[kx][ky] == 0) {
				visit[kx][ky] = 1;
				dfs(kx, ky, c, d + 1);
				visit[kx][ky] = 0;
			}
			else if (arr[a][b] > arr[kx][ky] - k && visit[kx][ky] == 0 && c == 0) {
				int val = arr[kx][ky];
				arr[kx][ky] = arr[a][b] - 1;
				visit[kx][ky] = 1;
				dfs(kx, ky, 1, d + 1);
				arr[kx][ky] = val;
				visit[kx][ky] = 0;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		int ans = 0, ma = 0;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				if (ma < arr[i][j]) ma = arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ma == arr[i][j]) {
					visit[i][j] = 1;
					dfs(i, j, 0, 1);
					ans = max(chk, ans);
					chk = 0;
					memset(visit, 0, sizeof(visit));
				}
			}
		}
		printf("#%d %d\n", z, ans);

	}
	return 0;
}