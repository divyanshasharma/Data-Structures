  //https://leetcode.com/problems/minimum-window-substring/submissions/
  string minWindow(string s, string t) {
        int counnt=0;
    	map<char, int>m, mm;
	counnt = 0;
	for (int i = 0; i < t.size(); i++) {
		m[t[i]]++;
		mm[t[i]]++;
	}
	int st = 0,fs=0, len = INT_MAX;
	for (int i = 0; i < s.size(); i++) {
		if (mm.count(s[i])) {
			m[s[i]]--;
			if (m[s[i]] >= 0) {
				counnt++;
			}
		}
        else continue;
		while (counnt == t.length()) {
			if(len>(i - st + 1)){
                len=(i - st + 1);
                fs=st;
            }
			if (mm.count(s[st])) {
				m[s[st]]++;
				if (m[s[st]] > 0)counnt--;
			}
			st++;
		}
	}
        string h="";
	if (len > s.size())return "";
        for(int t=fs,i=0;t<s.size() &&i<len;i++,t++){
            h+=s[t];
        }
    return h;
    }
