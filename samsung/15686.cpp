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

int n, m, arr[55][55], visit[14], num2, num, ans = 987654321;
int x[101], y[101], xx[14], yy[14];

void dfs(int a, int b) {
	if (b == m) {
		//for (int i = 0; i < num2; i++) {
		//	printf("%d ", visit[i]);
		//}
		//printf("\n");
		int sum = 0;
		for (int i = 0; i < num; i++) {
			int dis = 987654321;
			for (int j = 0; j < num2; j++) {
				int chk = 0;
				if (visit[j] == 1) {
					chk = abs(x[i] - xx[j]) + abs(y[i] - yy[j]);
					dis = min(chk, dis);
				}
				//cout << chk << " ";
			}
			//cout << endl;
			sum = sum + dis;
		}
		ans = min(sum, ans);
		return;
	}
	for (int i = a; i < num2; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(i + 1, b + 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				xx[num2] = i;
				yy[num2] = j;
				num2++;
			}
			if (arr[i][j] == 1) {
				x[num] = i;
				y[num] = j;
				num++;
			}
		}
	}
	//for (int i = 0; i < num2; i++) printf("%d %d\n", xx[i], yy[i]);
	//cout << num << endl;
	dfs(0, 0);
	cout << ans;
	return 0;
}