//https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/submissions/

int minimumSwap(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return -1;
        }
        int ss=0,s=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x')
            {   // taking case of xy
                if(s1[i]!=s2[i])
                    s++;    
            }
            else if(s1[i]=='y'){ // taking case of yx
                if(s1[i]!=s2[i])
                    ss++;    
            }
        } 
        
        if((s%2)!=(ss%2))return -1;
        
        if((s%2)==0 && (ss%2)==0){
            return s/2+ss/2;
        }    
        
        if((s%2)==1 && (ss%2)==1){//handling 1xy & 1 yx case esparately in 2 steps & remaining same
            return (s-1)/2+(ss-1)/2 +2;
        }    
        return -1;
    }
