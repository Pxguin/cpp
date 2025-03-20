#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        char col; int row; cin >> col >> row;
        F0R(i,8) {
            if (i!=col-'a') {cout << (char)(i+'a')<<row<<'\n';}
            if (i!=row-1) {cout << col << i+1 <<'\n';}
        }
    }
}