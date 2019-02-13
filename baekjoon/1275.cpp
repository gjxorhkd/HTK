#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>
typedef long long ll;

using namespace std;

ll init(vector<ll> &a, vector<ll> &tree, int n, int s, int e) {
	if (s == e) return tree[n] = a[s];
	int mid = (s + e) / 2;
	return tree[n] = init(a, tree, n * 2, s, mid) + init(a, tree, n * 2 + 1, mid + 1, e);
}

void update(vector<ll> &tree, int n, int s, int e, int index, ll dif) {
	if (s > index || e < index) return;
	tree[n] = tree[n] + dif;
	if (s != e) {
		int mid = (s + e) / 2;
		update(tree, n * 2, s, mid, index, dif);
		update(tree, n * 2 + 1, mid + 1, e, index, dif);
	}
}

ll sum(vector<ll> &tree, int n, int s, int e, int l, int r) {
	if (l > e || r < s) return 0;
	if (l <= s && r >= e) return tree[n];
	int mid = (s + e) / 2;
	return sum(tree, n * 2, s, mid, l, r) + sum(tree, n * 2 + 1, mid + 1, e, l, r);
}

int main()
{
	int n, q;
	vector<ll> arr(100001), t(400000);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	init(arr, t, 1, 0, n - 1);
	for (int i = 0; i < q; ++i) {
		int x, y, a, b;
		ll ans = 0,num=0;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		//cout << x << " " << y << endl;
		ans = sum(t, 1, 0, n - 1, x - 1, y - 1);
		num = b - arr[a - 1];
		arr[a - 1] = b;
		update(t, 1, 0, n - 1, a - 1, num);
		printf("%lld\n", ans);
	}
	return 0;
}