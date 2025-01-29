#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s; char* cow_string = &s[0];
    int n = s.length();
    int q; cin >> q;
    int c = 0, o = 0, w = 0;
    pair<int,int> req; // request
    int c_parity, o_parity, w_parity;

    int sums[n+1][3];
    sums[0][0] = 0; sums[0][1] = 0; sums[0][2] = 0;
    for (int i=0;i<n;i++) {
        if (cow_string[i] == 'C') {c++;}
        else if (cow_string[i] == 'O') {o++;}
        else {w++;}
        sums[i+1][0] = c; sums[i+1][1] = o; sums[i+1][2] = w;
    }

    for (int i=0;i<q;i++) {
        cin >> req.first >> req.second;
        c_parity = (sums[req.second][0]-sums[req.first-1][0])%2;
        o_parity = (sums[req.second][1]-sums[req.first-1][1])%2;
        w_parity = (sums[req.second][2]-sums[req.first-1][2])%2;

        //cout << c_parity << o_parity << w_parity << endl;
        if (((c_parity == 0) && (o_parity == 1) && (w_parity == 1)) || ((c_parity == 1) && (o_parity == 0) && (w_parity == 0))) {
            cout << 'Y';
        } else {cout << 'N';}
    }
}