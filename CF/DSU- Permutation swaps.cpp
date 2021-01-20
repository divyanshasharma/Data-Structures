//https://www.interviewbit.com/problems/permutation-swaps/
//https://unacademy.com/class/graph-interview-problems-part-3/3SHQBYJN
int get(vector<int> &parent, int i) {
	return (parent[i] == i) ? i : get(parent, parent[i]);
}
void Union(vector<int>&parent, vector<int>&rank, int i, int j) {
	i = get(parent, i);
	j = get(parent, j);
	if (rank[i] == rank[j])rank[i]++;
	if (rank[i] > rank[j]) {
		rank[i] += rank[j];
		parent[j] = parent[i];
	}
	else {
		rank[j] += rank[i];
		parent[i] = parent[j];
	}
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
vector<int>parent(A.size() + 1, 0);
	for (int i = 1; i <= A.size(); i++) {
		parent[i] = i;
	}
	vector<int>rank(A.size() + 1, 1);
	for (int i = 0; i < C.size(); i++) {
		Union(parent, rank, A[C[i][1] - 1], A[C[i][0] - 1]);
	//as ab parent same ho jaenge connected component hone ke karan
	}
	for (int i = 0; i < B.size(); i++) {
		int h1 = get(parent, B[i]);
		int h2 = get(parent, A[i]);
		if (h1 != h2)return 0;
		// if parent same nhi then vo same connected component me lie nhi karenge so 
		// hm unhe nhi krr skte swap
	}
	return 1;
}

