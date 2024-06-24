#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define MAX_N 300001
 
int prime[MAX_N] = {0};
 
void calc_primes() {
    for (ll i=2;i<=MAX_N;i++) {
        if (!prime[i]) {
            prime[i] = i;
            for (ll p=i*i;p<=MAX_N;p+=i) {
                prime[p] = i;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    calc_primes();
    
    int n; cin >> n;
    int a;
    
    bool flag = false;
    int ctr = 0;
    
    vector<vector<int>> gcd(MAX_N), spiders(n);
    
    for (int i=0;i<n;i++) {
        cin >> a;
        int last = -1;

        while (a != 1) {
            if (prime[a] != last) {
                spiders[i].pb(prime[a]);
                gcd[prime[a]].pb(i);
            }
            last = prime[a];
            a /= prime[a];
        }
    }
    int s, t; cin >> s >> t; s--; t--;
	
	int vis_spiders[n] = {false};
	int vis_primes[MAX_N] = {false};
	vector<int> par(n, INT_MAX); 
    par[s] = -1;
    vis_spiders[s] = true;
	int ans = INT_MAX;
	queue<int> q; q.push(s);
 
	while (!q.empty()) {
		int x = q.front(); q.pop();
 
		for (int p : spiders[x]) {
			if (!vis_primes[p]) {
				vis_primes[p] = true;
				for (int sp : gcd[p]) {
					if (!vis_spiders[sp]) {
						par[sp] = x; 
						q.push(sp);
						vis_spiders[sp] = true;
					}
				}
			}
		}	
	}
	
    vector<int> path;
    int ptr = t;
 
    if (!vis_spiders[t]) {cout << "-1\n";}
    else {
        while (par[ptr] != -1) {path.pb(ptr); ptr = par[ptr];}
        path.pb(s);
        cout << path.size() << "\n";
        for (int i=path.size()-1;i>=0;i--) {cout << path[i]+1 << " ";}
    }
}
