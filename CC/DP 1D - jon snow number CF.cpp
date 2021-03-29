// https://codeforces.com/problemset/problem/768/C
//https://unacademy.com/class/1-d-dp-problem-solving-part-3/LMIMRMXX
void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	vii freq(1500, 0);
	fo(i, 0, n - 1) {
		int y;
		cin >> y;
		freq[y]++;
	}
	int p = 0;
	vii temp(1500, 0);
	fo(j, 0, k - 1) {
		p = 0;
		fo(i, 0, 1499) {
			temp[i] = freq[i];
		}
		fo(i, 0, 1499) {

			if (freq[i] > 0) {
				int d = freq[i] / 2;
				if (p == 0) {
					d += (freq[i] & 1);
				}
				temp[i ^ x] += d;
				temp[i] -= d;
				p = p ^ (freq[i] & 1);
			}
		}
		fo(i, 0, 1499) {
			freq[i] = temp[i];
		}
	}
	int min_v = INT_MAX, max_v = INT_MIN;
	fo(i, 0, 1499) {
		if (freq[i] > 0)
		{
			max_v = max(max_v, i);
			min_v = min(min_v, i);
		}
	}
	cout << max_v << " " << min_v << endl;
}
