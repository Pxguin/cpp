#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<bool> prime(1000000*6+1,true);



void solve() {
    int n; cin >> n;
    int a;
    int turns;
    int min_turns = INT_MAX; int ans;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (a%4==0) {
            turns = a/2+1;
            if (turns < min_turns) {min_turns = turns; ans = 1;}
        } else {
            if (a%2==0) {turns = a/2;}
            else {
                for (int j=0;j<=(int)a/4;j++) {
                    if (prime[a-j*4]) {turns = 1+j*2; break;}
                }
            }
            if (turns < min_turns) {min_turns = turns; ans = 0;}
        }
    }
    if (ans == 1) {cout << "Farmer Nhoj" << "\n";} else {cout << "Farmer John" << "\n";}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for (int i=2;i*i<=1000000*6;i++) {
        if (prime[i]) {
            for (int j=i*i;j<=1000000*6;j+=i) {
                prime[j] = false;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }
}