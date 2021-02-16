//https://unacademy.com/class/internship-interview-problem-solving-2/WTBGQE0L
#include <bits/stdc++.h>
struct DLLNode {
	int key, value;
	DLLNode *prev, *next;
	DLLNode(int key, int value) {
		this->key = key;
		this->value = value;
		this->prev = NULL;
		this->next = NULL;
	}
};
unordered_map<int, DLLNode *>cache;
int size, capacity = 0;
DLLNode* head = new DLLNode(-1, -1);
DLLNode* tail = new DLLNode(-1, -1);
void addNodeatHead(DLLNode *node) {
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
	node->prev = head;
	return;
}

void removeNode(DLLNode *k) {
	DLLNode *p = k->next, *n = k->prev;
	n->next = p;
	p->prev = n;
}
int removeNodeFromTail() {
	DLLNode* nn = tail->prev;
	removeNode(nn);
	return nn->value;
}
void moveToHead(DLLNode *node) {
	cout << "Accessed the key " << node->key << endl;
	removeNode(node);
	addNodeatHead(node);
}
int get(int k) {
	if (cache.count(k) == 0) {
		cout << "Value is not present in the cache, please insert it first\n";
		return INT_MIN;
	}
	DLLNode * node = cache[k];
	moveToHead(node);
	return node->value;
}
void put(int k, int v) {
	if (cache.count(k) == 0) {
		DLLNode *node = new DLLNode(k, v);
		cache[k] = node;
		cout << "Added a new key " << k << endl;
		addNodeatHead(node);
		capacity++;
		if (capacity > (size)) {
			int removedKey = removeNodeFromTail();
			cout << "As the cache is full e need to remove the key ";
			cout << removedKey << endl;
			cache.erase(removedKey);
			capacity--;
		}
	}
	else {
		DLLNode *node = cache[k];
		node->value = v;
		moveToHead(node);
	}
}
void solve()
{
	cout << "Please enter the size of the cache ";
	cin >> size;
	cout << "Size of cache is " << size << endl;
	head->next = tail;
	tail->prev = head;
	int q;
	cin >> q;
	while (q--) {
		char ch;
		cin >> ch; // insert or get
		int k, v;
		if (ch == 'p') {
			//put
			cin >> k >> v;
			put(k, v);
		}
		else {
			// get
			cin >> k;
			int val = get(k);
			cout << "Value for key " << k << " is " << val << endl;
		}
	}
}
