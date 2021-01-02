/*
Goven an array 1<=a[i]<=n
some elements appeared twice, some appeared once only,
find all elements that are absent in the array


Don't use set because it stores in logn time & we need constant space also
*/

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	fo(i, 1, n) {
		cin >> a[i];
	}
	fo(i, 1, n) {
		if (a[abs(a[i])] > 0)
			a[abs(a[i])] = a[abs(a[i])] * (-1);
	}
	fo(i, 1, n) {
		if (a[i] > 0) {
			cout << i << " ";
		}
	}
}
