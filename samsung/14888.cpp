#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<tuple>
using namespace std;

int n, arr[13], op[5], visit[13], ans = -2000000000, ans2 = 2000000000;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &op[i]);
	for (int i = 0; i < n - 1; i++) {
		if (op[0] != 0) {
			visit[i] = 0;
			op[0]--;
		}
		else if (op[1] != 0) {
			visit[i] = 1;
			op[1]--;
		}
		else if (op[2] != 0) {
			visit[i] = 2;
			op[2]--;
		}
		else if (op[3] != 0) {
			visit[i] = 3;
			op[3]--;
		}
	}
	//for (int i = 0; i < n - 1; i++) printf("%d ", visit[i]);
	do {
		int chk = arr[0];
		for (int i = 0; i < n - 1; i++) {
			if (visit[i] == 0) {
				chk = chk + arr[i + 1];
			}
			else if (visit[i] == 1) {
				chk = chk - arr[i + 1];
			}
			else if (visit[i] == 2) {
				chk = chk * arr[i + 1];
			}
			else if (visit[i] == 3) {
				chk = chk / arr[i + 1];
			}
		}
		ans = max(chk, ans);
		ans2 = min(chk, ans2);
		//for (int i = 0; i < n - 1; i++) {
		//printf("%d ", visit[i]);
		//}
		//printf("\n");
	} while (next_permutation(visit, visit + n - 1) == 1);

	printf("%d\n%d\n", ans, ans2);
	return 0;
}