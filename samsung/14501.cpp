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

int n, arrt[16], arrp[16], ans;

void dfs(int a, int b) {
	//printf("%d\n", a);
	if (a > n + 1) return;
	if (a == n + 1) {
		ans = max(ans, b);
		return;
	}
	dfs(a + 1, b);
	dfs(a + arrt[a], b + arrp[a]);
}

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d %d", &arrt[i], &arrp[i]);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}