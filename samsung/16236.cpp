#include<iostream>
#include<math.h>
#include<stack>
#include<string.h>
#include<queue>
#include<algorithm>
#include<set>
#include<iterator>

using namespace std;

int n, m, arr[10][10], visit[9], cnt, map[10][10], gg[9], gg2[10];
int x[10], y[10], z[10], k, chk, ans = 987654321;


void five(int a, int b) {
	int kx = a, ky = b;
	//cout << kx << " " << ky << endl;
	for (int v = ky; v < m; v++) {
		ky++;
		if (arr[kx][ky] == 6) break;
		arr[kx][ky] = 8;
	}
	ky = b;

	for (int v = ky - 1; v >= 0; v--) {
		ky--;
		if (arr[kx][ky] == 6) break;
		arr[kx][ky] = 8;
	}
	ky = b;
	for (int v = kx; v < n; v++) {
		kx++;
		if (arr[kx][ky] == 6) break;
		arr[kx][ky] = 8;
	}
	kx = a;
	for (int v = kx - 1; v >= 0; v--) {
		kx--;
		if (arr[kx][ky] == 6) break;
		arr[kx][ky] = 8;
	}
}

void dfs(int tt) {
	if (tt == cnt) {
		//for (int i = 0; i < cnt; i++) {
		//printf("%d ", visit[i]);
		//}
		//printf("\n");
		for (int i = 0; i < k; i++) {
			five(gg[i], gg2[i]);
		}  // f\
		   		//serch(0);
		for (int a = 0; a < cnt; a++) {
			if (z[a] == 1) {
				if (visit[a] == 1) {
					int kx = x[a], ky = y[a];
					for (int v = ky; v < m; v++) {
						ky++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
				else if (visit[a] == 2) {
					int kx = x[a], ky = y[a];
					for (int v = kx; v < n; v++) {
						kx++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
				else if (visit[a] == 3) {
					int kx = x[a], ky = y[a];
					for (int v = ky - 1; v >= 0; v--) {
						ky--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
				else if (visit[a] == 4) {
					int kx = x[a], ky = y[a];
					for (int v = kx - 1; v >= 0; v--) {
						kx--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
			}

			else if (z[a] == 2) {
				if (visit[a] == 1 || visit[a] == 3) {
					int kx = x[a], ky = y[a];
					for (int v = ky; v < m; v++) {
						ky++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					ky = y[a];
					for (int v = ky - 1; v >= 0; v--) {
						ky--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
				else if (visit[a] == 2 || visit[a] == 4) {
					int kx = x[a], ky = y[a];
					for (int v = kx; v < n; v++) {
						kx++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = kx - 1; v >= 0; v--) {
						kx--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
			}

			else if (z[a] == 3) {
				if (visit[a] == 1) {
					int kx = x[a], ky = y[a];
					for (int v = kx - 1; v >= 0; v--) {
						kx--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = ky; v < m; v++) {
						ky++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}

				else if (visit[a] == 2) {
					int kx = x[a], ky = y[a];
					for (int v = ky; v < m; v++) {
						ky++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					ky = y[a];
					for (int v = kx; v < n; v++) {
						kx++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}

				else if (visit[a] == 3) {
					int kx = x[a], ky = y[a];
					for (int v = kx; v < n; v++) {
						kx++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = ky - 1; v >= 0; v--) {
						ky--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}

				else if (visit[a] == 4) {
					int kx = x[a], ky = y[a];
					for (int v = ky - 1; v >= 0; v--) {
						ky--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					ky = y[a];
					for (int v = kx - 1; v >= 0; v--) {
						kx--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
			}

			else if (z[a] == 4) {
				if (visit[a] == 1) {
					int kx = x[a], ky = y[a];
					for (int v = kx - 1; v >= 0; v--) {
						kx--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = ky; v < m; v++) {
						ky++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					ky = y[a];
					for (int v = ky - 1; v >= 0; v--) {
						ky--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
				else if (visit[a] == 2) {
					int kx = x[a], ky = y[a];
					for (int v = kx - 1; v >= 0; v--) {
						kx--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = ky; v < m; v++) {
						ky++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					ky = y[a];
					for (int v = kx; v < n; v++) {
						kx++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
				else if (visit[a] == 3) {
					int kx = x[a], ky = y[a];
					for (int v = kx; v < n; v++) {
						kx++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = ky; v < m; v++) {
						ky++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					ky = y[a];
					for (int v = ky - 1; v >= 0; v--) {
						ky--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
				else if (visit[a] == 4) {
					int kx = x[a], ky = y[a];
					for (int v = kx - 1; v >= 0; v--) {
						kx--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = kx; v < n; v++) {
						kx++;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
					kx = x[a];
					for (int v = ky - 1; v >= 0; v--) {
						ky--;
						if (arr[kx][ky] == 6) break;
						arr[kx][ky] = 8;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					chk++;
				}
			}
		}
		//for (int i = 0; i < n; i++) {
		//for (int j = 0; j < m; j++) {
		//printf("%d", arr[i][j]);
		//}
		//printf("\n");
		//}
		//printf("\n");
		ans = min(ans, chk);
		//printf("%d\n", ans);
		chk = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = map[i][j];
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		visit[tt] = i + 1;
		dfs(tt + 1);
		visit[tt] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			map[i][j] = arr[i][j];
			if (arr[i][j] != 6 && arr[i][j] != 0 && arr[i][j] != 5) {
				x[cnt] = i;
				y[cnt] = j;
				z[cnt] = arr[i][j];
				//cout << x[cnt] << " " << y[cnt] << " " << cnt << endl;
				cnt++;
			}
			if (arr[i][j] == 5) {
				gg[k] = i;
				gg2[k] = j;
				k++;
			}
		}
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}