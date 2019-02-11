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

int n, m, arr[10][10], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, visit[10][10];
int w[70], w2[70], b[70], b2[70], k, k2, chk, ans;
queue<pair<int, int>>q;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				w[k] = i;
				w2[k] = j;
				k++;
			}
			if (arr[i][j] == 2) {
				b[k2] = i;
				b2[k2] = j;
				k2++;
			}
		}
	}
	for (int i = 0; i < k - 2; i++) {
		int chk = 0;
		for (int j = i + 1; j < k - 1; j++) {
			for (int z = j + 1; z < k; z++) {
				for (int v = 0; v < k2; v++) {
					q.push(make_pair(b[v], b2[v]));
				}
				visit[w[i]][w2[i]] = 1;
				visit[w[j]][w2[j]] = 1;
				visit[w[z]][w2[z]] = 1;


				while (!q.empty()) {
					int x, y, kx, ky;
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int e = 0; e < 4; e++) {
						kx = x + dx[e];
						ky = y + dy[e];
						if (kx >= 0 && kx < n && ky >= 0 && ky < m) {
							if (arr[kx][ky] == 0 && visit[kx][ky] == 0) {
								visit[kx][ky] = 2;
								q.push(make_pair(kx, ky));
							}
						}
					}
				}
				for (int r = 0; r < n; r++) {
					for (int t = 0; t < m; t++) {
						if (visit[r][t] == 0 && arr[r][t] != 1 && arr[r][t] != 2) chk++;
					}
				}
				//for (int r = 0; r < n; r++) {
				//for (int t = 0; t < m; t++) {
				//printf("%d ", visit[r][t]);
				//}
				//printf("\n");
				//}
				//printf("\n\n");
				ans = max(ans, chk);
				chk = 0;
				memset(visit, 0, sizeof(visit));
				//printf("%d\n", chk);
			}
		}
	}
	printf("%d", ans);
	return 0;
}