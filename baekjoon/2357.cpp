#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

int init1(vector<int> &a, vector<pair<int,int>> &tree, int n, int s, int e) {
	if (s == e) return tree[n].first = a[s];
	int mid = (s + e) / 2;
	return tree[n].first = min(init1(a, tree, n * 2, s, mid) , init1(a, tree, n * 2 + 1, mid + 1,e));
}
int init2(vector<int> &a, vector<pair<int, int>> &tree, int n, int s, int e) {
	if (s == e) return tree[n].second = a[s];
	int mid = (s + e) / 2;
	return tree[n].second = max(init2(a, tree, n * 2, s, mid), init2(a, tree, n * 2 + 1, mid + 1, e));
}

int Min(vector<pair<int, int>> &tree, int n, int s, int e, int l, int r) {
	if (l > e || r < s) return 2000000000;
	if (l <= s && r >= e) return tree[n].first;
	int mid = (s + e) / 2;
	return min(Min(tree, n*2, s, mid, l, r), Min(tree, n*2+1, mid + 1, e, l, r));
}

int Max(vector<pair<int, int>> &tree, int n, int s, int e, int l, int r) {
	if (l > e || r < s) return -1;
	if (l <= s && r >= e) return tree[n].second;
	int mid = (s + e) / 2;
	return max(Max(tree, n*2, s, mid, l, r), Max(tree, n*2+1, mid + 1, e, l, r));
}

int main()
{
	int n, m;
	vector<int> arr(100001);
	vector<pair<int, int>> t(400004);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	init1(arr, t, 1, 0, n - 1);
	init2(arr, t, 1, 0, n - 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", Min(t, 1, 0,n-1,a - 1, b - 1), Max(t, 1,0,n-1, a - 1, b - 1));
	}
	return 0;
}