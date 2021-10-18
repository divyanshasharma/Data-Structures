//https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    string parsePattern(string p) {
        string ret;
        for (auto c: p) {
            if (c == '*') {
                if (ret.back() == '.') {
                    ret.back() = '*';
                } else {
                    ret.back() = toupper(ret.back());
                }
            } else {
                ret.push_back(c);
            }
        }
        return ret;
    }
    
    bool isMatch(string s, string p) {
        
        p = parsePattern(p);
        vector<vector<bool>> dp(p.length()+1, vector<bool>(s.length()+1, false));
        
        dp[0][0] = true; // An empty pattern matches an empty string.
        
        // first column
        for (int i = 1; i < dp.size(); ++i) {
            if (p[i-1] == '*' || p[i-1] >= 'A' & p[i-1] <= 'Z') {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = false;
            }
        }
        
        // rest of the dp table
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp.front().size(); ++j) {
                if (p[i-1] == '*') {
                    if (dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]) {
                      dp[i][j] = true;
                    }  
                } else if (p[i-1] == '.') {
                    if (dp[i-1][j-1] == true) {
                        dp[i][j] = true;
                    }
                } else if (p[i-1] >= 'A' && p[i-1] <= 'Z') {
                    if (dp[i-1][j] || tolower(p[i-1]) == s[j-1] && (dp[i-1][j-1] || dp[i][j-1])) {
                        dp[i][j] = true;
                    }
                } else {
                    if (p[i-1] == s[j-1] && dp[i-1][j-1] == true) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[dp.size()-1][dp.front().size()-1];
        
    }
};
