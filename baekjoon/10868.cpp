#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

int init(vector<int> &a, vector<int> &tree, int n, int s, int e) {
	if (s == e) return tree[n] = a[s];
	int mid = (s + e) / 2;
	return tree[n] = min(init(a, tree, n*2, s, mid) , init(a, tree, n*2+1, mid + 1, e));
}

int M(vector<int> &tree, int n, int s, int e, int L, int R) {
	if (L > e || R < s) return 987654321;
	if (L <= s && R >= e) return tree[n];
	int mid = (s + e) / 2;
	return min(M(tree, n * 2, s, mid, L, R) , M(tree, n * 2 + 1, mid + 1, e, L, R));
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr(100001);
	vector<int> t(400004);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	init(arr, t, 1, 0, n - 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", M(t, 1, 0, n - 1, a - 1, b - 1));
	}
	return 0;
}