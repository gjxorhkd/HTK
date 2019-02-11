#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<deque>

using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, visit[55][55], arr[55][55], ans;
int n, m, a, b, l, chk;
queue<pair<int, int>>q;

void bfs(int a, int b) {
	ans++;
	q.push(make_pair(a, b));
	while (--l) {
		int sz = q.size();
		//if (sz == 0) break;
		for (int w = 0; w < sz; w++) {
			int x, y, kx, ky;
			x = q.front().first;
			y = q.front().second;
			//printf("%d %d ", x, y);
			q.pop();
			for (int i = 0; i < 4; i++) {
				kx = x + dx[i];
				ky = y + dy[i];
				if (kx >= 0 && kx < n && ky >= 0 && ky < m && visit[kx][ky] == 0) {
					if (arr[x][y] == 1) {
						if ((dx[i] == 1) && (arr[kx][ky] == 1 || arr[kx][ky] == 2 || arr[kx][ky] == 4 || arr[kx][ky] == 7)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dx[i] == -1) && (arr[kx][ky] == 1 || arr[kx][ky] == 5 || arr[kx][ky] == 6 || arr[kx][ky] == 2)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dy[i] == 1) && (arr[kx][ky] == 3 || arr[kx][ky] == 1 || arr[kx][ky] == 6 || arr[kx][ky] == 7)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dy[i] == -1) && (arr[kx][ky] == 3 || arr[kx][ky] == 4 || arr[kx][ky] == 5 || arr[kx][ky] == 1)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}

					}
					else if (arr[x][y] == 2) {
						if ((dx[i] == 1) && (arr[kx][ky] == 1 || arr[kx][ky] == 4 || arr[kx][ky] == 7 || arr[kx][ky] == 2)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dx[i] == -1) && (arr[kx][ky] == 1 || arr[kx][ky] == 5 || arr[kx][ky] == 6 || arr[kx][ky] == 2)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}

					}
					else if (arr[x][y] == 3) {
						if ((dy[i] == 1) && (arr[kx][ky] == 1 || arr[kx][ky] == 6 || arr[kx][ky] == 7 || arr[kx][ky] == 3)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dy[i] == -1) && (arr[kx][ky] == 1 || arr[kx][ky] == 5 || arr[kx][ky] == 4 || arr[kx][ky] == 3)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
					}
					else if (arr[x][y] == 4) {
						if ((dx[i] == -1) && (arr[kx][ky] == 1 || arr[kx][ky] == 2 || arr[kx][ky] == 5 || arr[kx][ky] == 6)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dy[i] == 1) && (arr[kx][ky] == 1 || arr[kx][ky] == 6 || arr[kx][ky] == 7 || arr[kx][ky] == 3)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
					}
					else if (arr[x][y] == 5) {
						if ((dx[i] == 1) && (arr[kx][ky] == 1 || arr[kx][ky] == 4 || arr[kx][ky] == 7 || arr[kx][ky] == 2)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dy[i] == 1) && (arr[kx][ky] == 1 || arr[kx][ky] == 3 || arr[kx][ky] == 6 || arr[kx][ky] == 7)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
					}
					else if (arr[x][y] == 6) {
						if ((dx[i] == 1) && (arr[kx][ky] == 1 || arr[kx][ky] == 7 || arr[kx][ky] == 4 || arr[kx][ky] == 2)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dy[i] == -1) && (arr[kx][ky] == 1 || arr[kx][ky] == 5 || arr[kx][ky] == 4 || arr[kx][ky] == 3)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
					}
					else if (arr[x][y] == 7) {
						if ((dx[i] == -1) && (arr[kx][ky] == 1 || arr[kx][ky] == 6 || arr[kx][ky] == 5 || arr[kx][ky] == 2)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
						else if ((dy[i] == -1) && (arr[kx][ky] == 1 || arr[kx][ky] == 3 || arr[kx][ky] == 5 || arr[kx][ky] == 4)) {
							visit[kx][ky] = 1;
							//q.push(make_pair(kx, ky));
						}
					}
					if (visit[kx][ky] == 1) {
						q.push(make_pair(kx, ky));
						ans++;
					}
				}
			}
		}
		//chk++;
		//if (chk == l-1) break;
		//printf("\n");
	}
}

int main()
{
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		scanf("%d %d %d %d %d", &n, &m, &a, &b, &l);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		visit[a][b] = 1;
		bfs(a, b);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//if (visit[i][j] == 1) ans++;
				//printf("%d", visit[i][j]);
			}
			//	printf("\n");
		}
		printf("#%d %d\n", z, ans);
		ans = chk = 0;
		memset(visit, 0, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		while (!q.empty()) q.pop();
	}
	return 0;
}