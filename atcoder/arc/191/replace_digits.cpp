#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
short s[N], t[N];
int freq[10] = {0};
bool done[10] = {false};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i=0;i<n;i++) {
        char c; cin >> c; 
        s[i] = (c-'0');
    }
    for (int i=0;i<m;i++) {
        char c; cin >> c;
        t[i] = (c-'0');
        freq[t[i]]++;
    }
    int dig = 9;
    for (int p=0;p<n;p++) { // greedily replace digits in s
        while (dig && freq[dig]==0) {dig--;}
        if (dig) {
            if (s[p]<dig) { // if replacing with the digit is better
                s[p] = dig;
                freq[dig]--;
            }
        }
        done[s[p]] = true;
    }
    if (freq[t[m-1]]!=0 && !done[t[m-1]]) {s[n-1] = t[m-1];} // need to include last digit of t
    for (int i=0;i<n;i++) {cout << s[i];}
}