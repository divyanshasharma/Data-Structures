/* this node was failing because
lets take an e.g of 
cc
da /df
ee

here we can say that c->d->e
but we can't say anything about f & a
here this code is failing for that Leetcode problem  because it has already provided us the order which is the dictionary for the question
e.g we have answer as acde / facde / cabde/ cfbde but we want only specific cabde

this code is helpgul when we are predicting our own dictionsry & to check cycle  like that of given in gfgs
*/










//GFG string findOrder(string dict[], int N, int k) {
    // Your code here
    
    unordered_map<char,int>ind;
    unordered_map<char, list<char> >m;//vertex & neighbours
    for(int i=0;i<N;i++){
        for(int j=0;j<dict[i].size();j++){
           // list<char>li;
        //    m[dict[i][j]]=li;  as it was giving TLE
            ind[dict[i][j]]=0;
        }
    }
    for(int i=1;i<N;i++){
        string a=dict[i-1];
        string b=dict[i];
        auto r=mismatch(b.begin(),b.end(),a.begin());
        if(a.size()>b.size() && r.first==b.end()){
            return "";
        }
        for(int j=0;j<min(a.size(),b.size());j++){
            if(a[j]!=b[j]){
                ind[b[j]]++;
                m[a[j]].push_back(b[j]);
                break;
            }
        }
    }
    string r="";
        queue<char>q;
        for(auto itr=ind.begin();itr!=ind.end();itr++){
            if(itr->second==0){
                q.push(itr->first);
            }
        }
        while(!q.empty()){
            auto c=q.front();
            q.pop();
            r+=c;
            for(auto &i:m[c]){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }
        }
        if(r.size()==k)return r;
        else return "";
}




//second one

string findOrder(vector<string>&words, int N, int k) {
    // graph bna rhe phle
    unordered_map<char,list<char>>adjList;//char & corresponding vertices
    unordered_map<char,int>ind;
    for(int i=0;i<N;i++){
        string str=words[i];
        for(int j=0;j<str.size();j++){
            char ch=str[j];
            ind[ch]=0;
            list<char>li;
            adjList[ch]=li;
        }
    }
    for(int i=0;i<N-1;i++){
        string w1=words[i],w2=words[i+1];
        auto r=mismatch(w2.begin(),w2.end(),w1.begin());
        if(w1.size()>w2.size() && r.first==w2.end()){//prefix wala case
            return "";
        }
        for(int j=0;j<min(w1.size(),w2.size());j++){
            if(w1[j]!=w2[j]){
                adjList[w1[j]].push_back(w2[j]);
                ind[w2[j]]+=1;
                break;
            }
        }
    }
    string res="";
    queue<char>qu;
    for(auto itr=ind.begin();itr!=ind.end();itr++){
        if(itr->second==0){
            qu.push(itr->first);
        }
    }
    while(!qu.empty()){
        char ch=qu.front();
        qu.pop();
        res+=ch;
        for(char &neighbour:adjList[ch]){
            ind[neighbour]-=1;
            if(ind[neighbour]==0){
                qu.push(neighbour);
            }
        }
    }
    if(res.size()==k)
    return res;
    return "";
}
    bool isAlienSorted(vector<string>& words, string order) {
        string h=findOrder(words, words.size(), order.size());
        unordered_map<char,int>m;
        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
        int p=0;
        for(int l=1;l<h.size();l++){
            if(m[h[l]]<m[h[l-1]])return 0;
        }
        return 1;
    }
};










