#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int a[5000], mod[50001];
using T = pair<int,int>;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;

    F0R(i,n) {cin >> a[i];}
    F0R(i,a[0]) {mod[i] = INT_MAX;}
    mod[0] = 0;
    priority_queue<T,vector<T>,greater<T>> pq;
    pq.push({0,0});
    while (pq.size()) { // dijkstra
        auto[d,x] = pq.top(); pq.pop();
        if (d!=mod[x]) {continue;}
        F0R(i,n) {
            int to = (x+a[i])%a[0];
            if (d+a[i]<=1e9 && d+a[i]<mod[to]) {
                pq.push({mod[to]=d+a[i],to});
            }
        }
    }
    int k; cin >> k;
    F0R(i,k) {
        int b; cin >> b;
        cout << (mod[b%a[0]]<=b ? "TAK" : "NIE") << '\n'; // check if min sum for that mod is smaller than this b
    }
}