#https://cses.fi/problemset/task/1655/
class trieNode {
public:
	trieNode *left = NULL, *right = NULL;
};
void insertt(int n, trieNode *head) {
	trieNode *curr = head;
	rfo(i, 31, 0) {
		int b = (n >> i) & 1;
		if (b == 0) {
			if (!curr->left) {
				curr->left = new trieNode();
			}
			curr = curr->left;
		}
		else {
			if (!curr->right) {
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}
int findMaxXor(trieNode *head, int n, int ai) {// This function will return the maximun xor value available for ai
	int val = ai;
	trieNode* curr = head;
	int curr_Xor = 0;
	rfo(j, 31, 0) {
		int b = (val >> j) & 1;
		if (b == 0) {
			if (curr->right) {
				curr_Xor += pow(2, j);
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		else {
			if (curr->left) {
				curr_Xor += pow(2, j);
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
	}

	return curr_Xor;
}
void solve()
{
	int n;
	cin >> n;
	int a[n];
	int c = 0;
	int q = INT_MIN;
	trieNode *r = new trieNode();
	fo(i, 0, n - 1) {
		cin >> a[i];
		c ^= a[i];
		insertt(c, r);
		q = max(max(c, q), findMaxXor(r,  n, c));
	}
	cout << q;
}
signed main() {
	FIO
	INPUT();
	int t;
	//cin >> t;
	t = 1;
	fo(i, 0, t - 1)
	{
		solve();
	}
	return 0;
}
