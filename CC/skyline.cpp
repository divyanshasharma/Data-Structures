https://briangordon.github.io/2014/08/the-skyline-problem.html

the point will be either the start or the end of any rectangle
see if start point in needed to be included or not samr we'll see for end point

we'll differentiate start & the end pt then we'll preprocess them
 so flag to differentiate
height-ve then start point
height +ve then end point

sort as we want answer in increasing order on the basis off x cordinate
but all these points aren't going to our ans as there would be shadowed or overlapped rect

core concept- wewant to travel on rectangl that has more height

of the active rectangles get the maximum height 
/////important point: on what point the height altered use that point in your answr

if we encountered an end point that means the count of active rect decreased so decrease the count 
by removing that rectangle from your bucket

if the removed height is equal to the height of the rectangle that we were considering then 
include that point in your answr

to waht height now we'll go?- on the max height of the bucket's active rectangle


bucket me 0 daal krr rakho if no active rect case comes then include 0


this bucket is priority queue as we want maximum till now

if curr hght == max hgt at end point then no need to do anything


case of tension:
	
	let say end pt says remove 10 
	but on the peak of our pq we have 12 then we use pq.remove(10);//complexity will be more
	for this case
	
	
	case: x cord same then how'll u sort: on the basis of height in increasing order
	so -ve wala kaam aaega
		___
	   | __|10
	   | | |8
	----------
	   2 4 6
	   
	   {2,-10}{4,-8}{6,8}{6,10}
	   as we dont want to add redundant points
 case 2:
 		____
	   |__  |10
	   |  | |8
	----------
	   2 4 6
	   
	   this case will also cover if we sort with res to hght in increasing order
	   
	   
	   
	   
	   
	   
	   
	   
	  class Solution {
public:
   
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>events;
        for(int i=0;i<buildings.size();i++)
        {
            int s=buildings[i][0];
            int e=buildings[i][1];
            int h=buildings[i][2];
            events.push_back({s,-h,0});
            events.push_back({e,h,1});
        }
        sort(events.begin(),events.end());
        vector<vector<int>>ans;
        
        multiset<int>st;
        int maxheight=0;
        for(int i=0;i<events.size();i++)
        {
            int curlocation=events[i][0];
            int curheight=abs(events[i][1]);
            int status=events[i][2];
            if(status==0)
            {
                st.insert(curheight);
                if(maxheight!=*st.rbegin())
                {
                    maxheight=*st.rbegin();
                    ans.push_back({curlocation,maxheight});
                }
            }
            else
            {
                auto x=st.find(curheight);
                st.erase(x);
                
                if(st.empty())
                {
                    maxheight=0;
                    ans.push_back({curlocation,maxheight});
                }
                else
                {
                   if(maxheight!=*st.rbegin())
                   {
                    maxheight=*st.rbegin();
                    ans.push_back({curlocation,maxheight});
                   }
                }
            }

        }
        
        return ans;
    }
}; 
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
The basic idea is:
1.put the start and end of each rectangle into a multimap, we will scan it later. The second parameter of the pair is its height.(i.e. as for [0,5,3] we will put {0, 3} and {5, -3} into the map)
2.for each element in multimap, if the height is greater than zero, we put it into multiset, else we find and erase it from the set.
3. the multiset means at each x value, the existing rectangle.
4. After processing each x value, the max in the set is what we need, just put it into the vector.	   
	   
	   struct point{
	int dist,height, type;
	poin(int d, int h, int t){
		this->dist=d;
		this->height=h;
		this->type=t;
	}
};
static bool cmp(piunt p1, point p2){
	if(p1.dist<p2.dist)return true;// smaller x axis point first
	else if(p1.dist==p2.dist){
									// start start clash
		if(p1.type==0 && p2.type==0){
			return p1.height>p2.height;
		}
		else if(p1.type==1 && p2.type==1){//end-end clash
			return p1.height<p2.height;
		}
		else return p1.type==0;// push start before 
	}
	else return false;
}
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
	vector<vector<int>>res;
	vector<point>p;
	multiset<int>s;
	s.insert(0);
	for(auto b: buildings){
		p.push_back(point(b[0],b[2],0));
		p.push_back(point(b[1],b[2],0));
	}
	sort(p.begin(), p.end(), cmp);
	for(auto pt: p){
		int prev_max=*s.rbegin();
		if(pt.type==0){
			s.erase(pt.height);
		}
		else{
			s.erase(s.find(pt.height));
		}
		int curr_max=*s.rbegin();
		if(curr_max!=prev_max){
			res.push_back({pt.dist, curr_max});
		}
		return res;
		
		
	}
}
