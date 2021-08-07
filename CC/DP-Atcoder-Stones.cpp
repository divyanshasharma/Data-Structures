In this problem there is no restriction on how to pick a stone
but only condition given is that players should pick stones alternatively
							f(n)//It this is a winning state then
							/\   \
						   /  \   \
						a[0] a[1]	a[n-1]//All of them should be loosing states
		As both the players are witty 
		so we have to play optimally
		at 0 the state will be loosing for Taru because he wont have any stone to pick
		
		Now simply make the recurrence
		
		
//https://atcoder.jp/contests/dp/tasks/dp_k	
	void solve() {
    int n, k;
    cin >> n >> k;
    vii a(n);
    fo(i, 0, n - 1) {
        cin >> a[i];
    }
    vii dp(k + 1, 0);//initially all the states are loosing state
    for (int i = 1; i <= k; i++) {
        fo(j, 0, n - 1) {
            if (i >= a[j])
                if (dp[i - a[j]] == 0)//If we found any looding state then current state will become the winning state for us
                    dp[i] = 1;
        }
    }
    if (dp[k] == 0) {//Final state is loosing state
        cout << "Second\n";
        return;
    }
    cout << "First\n";
}
