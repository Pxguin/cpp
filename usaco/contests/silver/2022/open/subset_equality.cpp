#include <bits/stdc++.h>
using namespace std;

int n;
bool pairs[18][18];
string s; string t;

char cmp(string &z) {
	for (int i=0;i<z.size();i++) {
		for (int j=i;j<z.size();j++) {
			if (!pairs[z[i]-'a'][z[j]-'a']) {return 'N';}
		}
	}
	return 'Y';
}


bool check(const char& a, const char& b) {
	string s1 = "";
	string s2 = "";
	for (char i : s) {
		if (i == a || i == b) {s1 += i;}
	} for (char i : t) {
		if (i == a || i == b) {s2 += i;}
	}

	return s1 == s2;
}

int main() {
	cin >> s >> t;
	int q; cin >> q;
	n = s.size();
	
	for (int i=0;i<18;i++) {
		for (int j=i;j<18;j++) {
			pairs[i][j] = check(i+'a', j+'a');
			pairs[j][i] = pairs[i][j];
		}
	}

	string z;
	for (int i=0;i<q;i++) {
		cin >> z;
		cout << cmp(z);
	}
}