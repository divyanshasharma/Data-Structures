//https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
//  Graph Interview 2 Snket Singh

int Solution::solve(int n, vector<int> &B, vector<int> &C) {
vector<int>v[n + 1];
    vector<int>ind(n + 1, 0);
    vector<int>vis(n + 1, 0);
    queue<int>q;
    for (int i = 0; i < B.size(); i++) {
        if (B[i] == C[i])return 0;
        v[B[i]].push_back(C[i]);
        ind[C[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0)q.push(i);
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (vis[t])continue;
        vis[t] = 1;
        for (int i = 0; i < v[t].size(); i++) {
            ind[v[t][i]]--;
            if (ind[v[t][i]] == 0) {
                q.push(v[t][i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0)return 0;
    }
    return 1;
}
























