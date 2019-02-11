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

int n, arr[21][21], visit[21], ans[6], k = 1, ans2[6], k2 = 1, aaa, bbb = 987654321;

int cal(int a[]) {
	int ss = 0;
	int len = n / 2;
	for (int i = 1; i <= len; i++) {
		for (int j = i + 1; j <= len; j++) {
			ss += arr[a[i]][a[j]];
			ss += arr[a[j]][a[i]];
		}
	}
	return ss;
}

void dfs(int a, int b) {
	//printf("%d\n", a);
	if (b == n / 2) {
		for (int i = 1; i <= n; i++) {
			//printf("%d ", visit[i]);
			if (visit[i] == 1) {
				ans[k] = i;
				k++;
			}
			else {
				ans2[k2] = i;
				k2++;
			}
		}
		int s = cal(ans);
		int l = cal(ans2);
		aaa = abs(s - l);
		bbb = min(bbb, aaa);
		//printf("%d %d\n", s, l);
		//for (int i = 1; i < k; i++) printf("%d ", ans[i]);
		//printf("\n");
		//for (int i = 1; i < k; i++) printf("%d ", ans2[i]);
		//printf("\n");
	}
	k = k2 = 1;
	//for (int i = 1; i <= n; i++) {
	//printf("%d ", visit[i]);
	//}
	//printf("\n");
	for (int i = a; i <= n; i++) {
		//if (visit[i] == 0 && a <= n) {
		visit[i] = 1;
		if (visit[1] == 0) return;
		//chk++;
		dfs(i + 1, b + 1);
		//chk--;
		visit[i] = 0;
		//}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(1, 0);
	printf("%d", bbb);
	return 0;
}