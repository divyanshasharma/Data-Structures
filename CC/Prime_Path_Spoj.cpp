//https://www.spoj.com/problems/PPATH/
vector<int>p;
vector<int>adj[10000];
bool isValid(int a, int b) {
	int c = 0;
	while (a) {
		if ((a % 10) != b % 10)c++;
		a /= 10;
		b /= 10;
	}
	if (c == 1)return 1;
	return 0;
}
bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}

void graph() {
	for (int i = 1000; i <= 9999; i++) {
		if (isPrime(i)) {
			p.push_back(i);
		}
	}
	for (int i = 0; i < p.size(); i++) {
		for (int j = i + 1; j < p.size(); j++) {
			if (isValid(p[i], p[j])) {
				adj[p[i]].push_back(p[j]);
				adj[p[j]].push_back(p[i]);
			}
		}
	}
}
void solve() {
	int a;
	int b;
	cin >> a >> b;
	vii vis(100001, 0), dist(100001, -1);
	queue<int>q;
	q.push(a);
	dist[a] = 0;
	vis[a] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int child : adj[t]) {
			if (vis[child] == 0) {
				vis[child] = 1;
				dist[child] = 1 + dist[t];
				q.push(child);
			}
		}
	}
	if (dist[b] == -1)cout << "Impossible\n";
	else {
		cout << dist[b] << endl;
	}
}
signed main() {

	FIO
	INPUT();

	int t;
	cin >> t;
	//t = 1;
	graph();
	fo(i, 0, t - 1)
	{
		solve();
	}
	return 0;
}
