#include <bits/stdc++.h>
void perm(string g, string o){
	if(g.size()==0){
		cout<<o<<endl;
		return;
	}
    //local because ek particular g string ke liye calls hme prune krni hain
    unordered_set<char>m;
	for(int i=0;i<g.size();i++){
    {
        char ch=g[i];
        if(m.count(ch)==0){
            string f=g.substr(0,i)+g.substr(i+1);
            m.insert(ch);
            perm(f,o+ch);
        }
        }
	}
}
void solve()
{
	string g;
	cin >> g ;
	string h="";
	perm(g,h);
}
