#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int cards[n];
    int p1 = 0; int p2 = n-1;
    for (int i=0;i<n;i++) {cin >> cards[i];}
    int s = 0; int d = 0;
    bool state = false;
    
    while (p1 <= p2) {
        if (cards[p1] > cards[p2]) {s += cards[p1]; p1++;}
        else {s += cards[p2]; p2--;}
        swap(s,d);
        state = !state;
    }
    if (state) {swap(s,d);}
    cout << s << " " << d;
}