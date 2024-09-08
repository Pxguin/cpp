#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

// fast io taken from usaco guide https://usaco.guide/general/fast-io
const int MOD = 1e9 + 7;
const int BUF_SZ = 1 << 15;

inline namespace Input {
	char buf[BUF_SZ];
	int pos;
	int len;
	char next_char() {
		if (pos == len) {
			pos = 0;
			len = (int)fread(buf, 1, BUF_SZ, stdin);
			if (!len) { return EOF; }
		}
		return buf[pos++];
	}
	int read_int() {
		int x;
		char ch;
		int sgn = 1;
		while (!isdigit(ch = next_char())) {
			if (ch == '-') { sgn *= -1; }
		}
		x = ch - '0';
		while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
		return x * sgn;
	}
}  // namespace Input
inline namespace Output {
	char buf[BUF_SZ];
	int pos;

	void flush_out() {
		fwrite(buf, 1, pos, stdout);
		pos = 0;
	}
	void write_char(char c) {
		if (pos == BUF_SZ) { flush_out(); }
		buf[pos++] = c;
	}
	void write_int(int x) {
		static char num_buf[100];
		if (x < 0) {
			write_char('-');
			x *= -1;
		}
		int len = 0;
		for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
		write_char((char)('0' + x));
		while (len) { write_char(num_buf[--len]); }
	}
	// auto-flush output when program exits
	void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output

int main() {
	init_output();
	
	int m; cin >> m;
	vector<int> a(m+2); a[0] = INT_MAX; a[m+1] = -1;
	F0R(i,m) {a[i+1] = read_int();}
	vector<vector<int>> diff(2*m);
	F0R(i,m) {diff[a[i+1]-i+m].pb(i+1);}
	vector<int> nearest(m+1), range(m+1,-2);

	stack<int> low, high; 
	vector<int> st;

	high.push(0); // nearest greater values on left
	F0R(i,m) {
		while (a[high.top()]<a[i+1]) {high.pop();}
		nearest[i+1] = high.top(); high.push(i+1);
	}

	F0R(i,2*m) {
		for (int x : diff[i]) {
			while (st.size() && st.back()>nearest[x]) {
				range[st.back()] = x; st.pop_back();
			} st.pb(x);
		} st.clear();
	}
	
	low.push(m+1); // nearest smaller values on right
	for (int i=m-1;i>=0;i--) {
		while (a[low.top()]>a[i+1]) {low.pop();}
		nearest[i+1] = low.top(); low.push(i+1);
	}

	F0R(i,m) {
		if (range[i+1]!=-2 && nearest[i+1]>range[i+1]) { // valid empodio
			while (st.size() && range[st.back()]>=range[i+1]) {st.pop_back();}
			st.pb(i+1);
		}
	}
	cout << st.size() << '\n';
	for (int i : st) {write_int(i); write_char(' '); write_int(range[i]); write_char('\n');}
}