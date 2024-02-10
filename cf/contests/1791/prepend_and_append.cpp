#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
void solve() {
	int n; cin >> n;
	bool a[n]; 
	char x;
	for (int i=0;i<n;i++) {
	    cin >> x;
	    if (x == '1') {a[i] = 1;}
	    else {a[i] = 0;}
	}
	
	int p1 = 0, p2 = n-1;
	while (p2-p1 >= 1) {
	    if (a[p1]^a[p2]) {p1++; p2--;}
	    else {break;}
	}
	cout << p2-p1+1 << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
