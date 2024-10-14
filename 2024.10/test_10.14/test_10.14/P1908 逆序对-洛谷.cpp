#include <iostream>

typedef long long ll;

using namespace std;

const int N = (int)1e6 + 10;

int q[N], tmp[N];

ll merge_sort(int l, int r, int q[])
{
	if (l >= r) return 0;

	int mid = (l + r) >> 1;

	ll res = merge_sort(l, mid, q) + merge_sort(mid + 1, r, q);

	int i = l, j = mid + 1, k = 0;

	while (i <= mid && j <= r)
		if (q[i] <= q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++], res += mid - i + 1;

	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];

	for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];

	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i];

	ll res = merge_sort(0, n - 1, q);

	cout << res << endl;

	return 0;
}