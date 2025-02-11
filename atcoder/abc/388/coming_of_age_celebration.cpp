#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    priority_queue<int,v<int>,greater<int>> pq;
    F0R(i,n) {
        while (pq.size() && pq.top()==i) {pq.pop();} // if aliens run out of stones then delete them

        int a; cin >> a;
        a += pq.size(); // take a stone from all aliens
        pq.push(a+i+1); // this is when it gives all its stones away
        
        if (a+i<n) {cout << 0 << ' ';} // will it run out of stones
        else {cout << (a+i)-n+1 << ' ';} // or will it have stones remaining
    }
}