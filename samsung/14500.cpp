#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<stack>

using namespace std;

int arr[510][510];

int main()
{
	int n, m, ans[19] = { 0 }, a = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j <= m && j + 3 <= m) // ㅡ
				ans[0] = max(arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3], ans[0]);

			if (i <= n && i + 3 <= n)// ㅣ
				ans[1] = max(arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j], ans[1]);

			if ((i <= n && j <= m) && (i + 1 <= n && j <= m) && (i <= n && j + 1 <= m) && (i + 1 <= n && j + 1 <= m)) // ㅁ모양
				ans[2] = max(arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1], ans[2]);

			if ((i <= n && j <= m) && (i + 1 <= n && j <= m) && (i + 1 <= n && j + 1 <= m) && (i + 2 <= n && j + 1 <= m))  //ㄱㄴ 모양
				ans[3] = max(arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1], ans[3]);

			if ((i + 1 <= n && j <= m) && (i + 1 <= n && j + 1 <= m) && (i <= n && j + 1 <= m) && (i <= n && j + 2 <= m))
				ans[4] = max(arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2], ans[4]);

			if ((i + 1 <= n && j <= m) && (i + 2 <= n && j <= m) && (i + 1 <= n && j + 1 <= m) && (i <= n && j + 1 <= m))
				ans[5] = max(arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1] + arr[i][j + 1], ans[5]);

			if ((i <= n && j <= m) && (i <= n && j + 1 <= m) && (i + 1 <= n && j + 1 <= m) && (i + 1 <= n && j + 2 <= m))
				ans[6] = max(arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2], ans[6]);

			if ((i <= n && j <= m) && (i <= n && j + 2 <= m) && (i + 1 <= n && j + 1 <= m) && (i <= n && j + 1 <= m)) //ㅜ
				ans[7] = max(arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1], ans[7]);

			if ((i + 1 <= n && j <= m) && (i <= n && j + 1 <= m) && (i + 2 <= n && j + 1 <= m) && (i + 1 <= n && j + 1 <= m)) // ㅓ
				ans[8] = max(arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1], ans[8]);

			if ((i + 1 <= n && j <= m) && (i <= n && j + 1 <= m) && (i + 1 <= n && j + 2 <= m) && (i + 1 <= n && j + 1 <= m)) // ㅗ
				ans[9] = max(arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2], ans[9]);

			if ((i <= n && j <= m) && (i + 2 <= n && j <= m) && (i + 1 <= n && j + 1 <= m) && (i + 1 <= n && j <= m)) // ㅏ
				ans[10] = max(arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1], ans[10]);

			if ((i <= n && j <= m) && (i + 2 <= n && j <= m) && (i + 2 <= n && j + 1 <= m) && (i + 1 <= n && j <= m)) // ㄴ 모양 8가지
				ans[11] = max(arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1], ans[11]);

			if ((i <= n && j <= m) && (i + 1 <= n && j <= m) && (i <= n && j + 2 <= m) && (i <= n && j + 1 <= m))
				ans[12] = max(arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2], ans[12]);

			if ((i <= n && j <= m) && (i <= n && j + 1 <= m) && (i + 2 <= n && j + 1 <= m) && (i + 1 <= n && j + 1 <= m))
				ans[13] = max(arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1], ans[13]);

			if ((i + 1 <= n && j <= m) && (i + 1 <= n && j + 2 <= m) && (i <= n && j + 2 <= m) && (i + 1 <= n && j + 1 <= m))
				ans[14] = max(arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2], ans[14]);

			if ((i + 2 <= n && j <= m) && (i + 2 <= n && j + 1 <= m) && (i <= n && j + 1 <= m) && (i + 1 <= n && j + 1 <= m))
				ans[15] = max(arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 1][j + 1] + arr[i][j + 1], ans[15]);

			if ((i <= n && j <= m) && (i + 1 <= n && j <= m) && (i + 1 <= n && j + 2 <= m) && (i + 1 <= n && j + 1 <= m))
				ans[16] = max(arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2], ans[16]);

			if ((i <= n && j <= m) && (i + 2 <= n && j <= m) && (i <= n && j + 1 <= m) && (i + 1 <= n && j <= m))
				ans[17] = max(arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j], ans[17]);

			if ((i <= n && j <= m) && (i <= n && j + 2 <= m) && (i + 1 <= n && j + 2 <= m) && (i <= n && j + 1 <= m))
				ans[18] = max(arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2], ans[18]);
		}
	}
	for (int i = 0; i < 19; i++) a = max(ans[i], a);
	cout << a;
	return 0;
}