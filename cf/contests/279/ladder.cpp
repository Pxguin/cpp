#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    
    int inc[n+1]; int dec[n+1];
    inc[0] = 0; dec[0] = 0;
    inc[1] = 1; dec[1] = 1;
    int a; int prev; cin >> prev;
    
    for (int i=2;i<n+1;i++) {
        cin >> a;
        inc[i] = 1; dec[i] = 1;
        if (a >= prev) {inc[i] = inc[i-1]+1;}
        if (a <= prev) {dec[i] = dec[i-1]+1;}
        prev = a;
    }
    
    int l, r;
    for (int i=0;i<m;i++) {
        cin >> l >> r; l--;
        bool ans = false;
        if (max(inc[r]-inc[l], dec[r]-dec[l]) >= r-l) {ans = true;}
        else {
            int mx = dec[r];
            if (mx + inc[r-mx+1]-1 >= r-l) {ans = true;}
        }
        cout << (ans == true ? "Yes" : "No") << "\n";
    }
}
