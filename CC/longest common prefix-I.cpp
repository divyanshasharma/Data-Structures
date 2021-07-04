//https://leetcode.com/problems/longest-common-prefix/submissions/
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        string ans=s[0];
        for(int i=1;i<n;i++)
        {
            int j=0;
            for(j=0;j<s[i].size() && j<ans.size();j++){
                if(s[i][j]!=ans[j]){
                    break;
                }
            }
                    ans=s[i].substr(0,j);
            
        }
        return ans;
    }
};
