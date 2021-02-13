
void lexi(int g, int i){
	if(i>g)return;
	else
		cout<<i<<endl;
	for(int k=(i==0?1:0);k<=9;k++){
		lexi(g,i*10+k);
	}
}
void solve()
{
	int g;
	cin >> g ;
	lexi(g,0);
}
//e.g 13
O/p
0
1
10
11
12
13
2
3
4
5
6
7
8
9


