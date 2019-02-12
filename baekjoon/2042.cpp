#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int n, int s, int e) {
	if (s == e) return tree[n] = a[s];
	int mid = (s + e) / 2;
	return tree[n] = init(a, tree, n*2, s, mid) + init(a, tree, n*2+1, mid + 1, e);
}

void update(vector<long long> &tree, int n, int s, int e, int index, long long dif) {
	if (s > index || e < index) return; // 
	tree[n] = tree[n] + dif;
	if (s != e) {
		int mid = (s + e) / 2;
		update(tree, n * 2, s, mid, index, dif);
		update(tree, n * 2 + 1, mid + 1, e, index, dif);
	}
}

long long sum(vector<long long> &tree, int n, int s, int e, int l, int r) {
	if (l > e || r < s) return 0;
	if (l <= s && r >= e) return tree[n];
	int mid = (s + e) / 2;
	return sum(tree, n * 2, s, mid, l, r) + sum(tree, n * 2 + 1, mid + 1,e, l, r);
}

int main()
{
	int n, m, k;
	vector<long long> arr(1000010), t(4000004);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	init(arr, t, 1, 0, n - 1);
	for (int i = 0; i < m + k; ++i) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long c, d=0;
			scanf("%d %lld", &b, &c);
			d = c - arr[b - 1];
			arr[b - 1] = c;
			//for (int i = 0; i < n; ++i) cout << arr[i] << " ";
			//printf("\n");
			update(t, 1, 0, n - 1, b - 1, d);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(t, 1, 0, n - 1, b - 1, c - 1));
		}
	}
	return 0;
}