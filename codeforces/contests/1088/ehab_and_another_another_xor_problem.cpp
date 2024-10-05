#include <bits/stdc++.h>
using namespace std;

int s, a = 0, b = 0;

int query(int c, int d) {
	int ret;
	cout << "? " << c << ' ' << d << endl;
	cin >> ret; return ret;
}

void calc(int& a, int& b, int i) {
	int q1 = query(a|i,b|i);
	int q2 = (s ? query(a,b|i) : query(a|i,b));
	if (s) {
		if (q1==-1) {
			a|=i;
			s = !(q2==-1);
		} else {
			if (q2!=-1) {a|=i; b|=i;}
		}
	} else {
		if (q1==1) {
			b|=i;
			s = (q2==1);
		} else {
			if (q2!=1) {a|=i; b|=i;}
		}
	}
}

int main() {
	s = (query(0,0)==1);
	for (int i=29;i>=0;i--) {
		calc(a,b,(1<<i));
	} cout << "! " << a << ' ' << b << endl;
}