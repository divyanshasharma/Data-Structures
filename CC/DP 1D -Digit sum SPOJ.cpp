// https://www.spoj.com/problems/CPCRC1C/

//https://unacademy.com/class/1-d-dp-problem-solving-part-3/LMIMRMXX
int poww(int a, int p) {
	int s = 1;
	while (p--) {
		s *= a;
	}
	return s;
}
int sum_of_digits(int b) {
	// this is our base case when one digit number is given only
	if (b / 10 == 0) {
		return (b * (b + 1)) / 2;
	}
	// to string in order to get the length 
	string bb = to_string(b);
	int n = bb.size();
	int po = (poww(10, n - 1));
	int l = b / (po);
	int s = 0, pc = poww(10, n - 2);
	fo(i, 0, l - 1) {
		//in order to get the number of elements present 
		// for one digit numbers any number will appear 1 times
		// for two digit numbers any number will appear 20 times
		// for three digit numbers any number will appear 300 times 
		// from this we can deduce the following pattern
		s += (i * po);
		s += (45 * (n - 1) * pc);
	}
	//for e.g. 3785 
	// we have already taken the cases for 1k,2k & 0k 
	// now for 3k
	s += l * (b % po + 1);// if 3785 then contribution of 3 will be in 786 numbers because we will also take the case of 3000
	s += sum_of_digits(b % po);// sum of 785di
	return s;
}
void solve() {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		int s = sum_of_digits(b) - sum_of_digits(a - 1);
		cout << s << endl;
	}
}

