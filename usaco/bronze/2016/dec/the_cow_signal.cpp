#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("cowsignal.in","r",stdin);
	freopen("cowsignal.out","w",stdout);

	int n, m, k; cin >> m >> n >> k;
	vector<vector<char>> signal(m*k, vector<char>(n*k));
	char x;
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cin >> x;
			for (int a=i*k;a<i*k+k;a++) {
				for (int b=j*k;b<j*k+k;b++) {
					signal[a][b] = x;
				}
			}
		}
	}
	for (int i=0;i<m*k;i++) {
		for (int j=0;j<n*k;j++) {cout << signal[i][j];}
		cout << '\n';
	}
	
}
