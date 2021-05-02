#https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/
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
int findMaxXor(trieNode *head, int *a, int n) {
	int maxXor = INT_MIN;
	fo(i, 0, n - 1) {
		int val = a[i];
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
		maxXor = max(maxXor, curr_Xor);
	}
	return maxXor;
}
void solve()
{
	int n;
	cin >> n;
	int a[n];
	trieNode *r = new trieNode();
	fo(i, 0, n - 1) {
		cin >> a[i];
		insertt(a[i], r);
	}
	cout << findMaxXor(r, a, n);
}

//Test Case
5
1 1 10 5 1
