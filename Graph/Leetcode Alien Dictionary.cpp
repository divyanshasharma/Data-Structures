//https://leetcode.com/problems/verifying-an-alien-dictionary/submissions/
class Solution {
public:
    
    bool isAlienSorted(vector<string>& a, string order) {
        unordered_map<char, int>dict;
        // here we have prepared our own dictionary, mapping of characters
        for(int i=0;i<order.size();i++){
            dict[order[i]]=i;
        }
        for(int i=1;i<a.size();i++){
            auto r=mismatch(a[i].begin(),a[i].end(),a[i-1].begin());
            if(a[i-1].size()>a[i].size() && r.first==a[i].end())//apple app prefix wala case ko avoid kraya
            {
                return 0;
            }
            //this case is now for detecting the first uncommon characters between the two words
            for(int j=0;j<min(a[i-1].size(),a[i].size());j++){
if(a[i-1][j]!=a[i][j]){
    // means this letter is larger in our dictionary but still coming before 
    if(dict[a[i-1][j]]>dict[a[i][j]]){                             
             return 0;
           }
            else
            {
                break; // e.g.  cbaa  daaa   ,as found correct so move to another word
            }
        }
     }   
        }
        return 1;
    }
};

//java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] index = new int[26];
        for (int i = 0; i < order.length(); ++i)
            index[order.charAt(i) - 'a'] = i;

        search: for (int i = 0; i < words.length - 1; ++i) {
            String word1 = words[i];
            String word2 = words[i+1];

            // Find the first difference word1[k] != word2[k].
            for (int k = 0; k < Math.min(word1.length(), word2.length()); ++k) {
                if (word1.charAt(k) != word2.charAt(k)) {
                    // If they compare badly, it's not sorted.
                    if (index[word1.charAt(k) - 'a'] > index[word2.charAt(k) - 'a'])
                        return false;
                    continue search;
                }
            }

            // If we didn't find a first difference, the
            // words are like ("app", "apple").
            if (word1.length() > word2.length())
                return false;
        }

        return true;
    }
}
