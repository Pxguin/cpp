#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<string> ad;
int k;
 
bool check(int w) {
    int p1 = 0;
    int len = 0;
    int lines = 1;
    while (p1 < ad.size()) {
        if (ad[p1].length() > w) {return false;}
        if (len+ad[p1].length() > w) {
            len = 0;
            if (++lines > k) {return false;}
        }
        len += ad[p1].length();
        p1++;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k;
    string s;
    string t = "";
    cin.ignore(); getline(cin, s);
    for (char c : s) {
        t += c;
        if (c == '-' || c == ' ') {
            ad.push_back(t);
            t = "";
        }
    } ad.push_back(t);
    
    int l = 1; int h = 1e6; int w = (l+h)/2;
    
    int ans = 0;
    while (l <= h) {
        if (check(w)) {
            h = w-1;
            ans = w;
        } else {l = w+1;}
        w = (l+h)/2;
        
    }
    cout << ans << "\n";
}