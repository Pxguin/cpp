#include <iostream>
#include <vector>

using namespace std;

vector<int> prefs[500];
int reachable[500][500];

void dfs(int source, int node) {
    reachable[source][node] = true;
    for (int node2 : prefs[node]) {
        if (!reachable[source][node2]) {dfs(source, node2);}
    }
}

int main() {
    int n; cin >> n;
    int pref;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> pref; pref--;
            if (pref != i) {prefs[i].push_back(pref);}
            else {
                prefs[i].push_back(pref);
                for (int k=j+1;k<n;k++) { cin >> pref; }
                break;
            }
        }
    }
    for (int i=0;i<n;i++) {dfs(i,i);}

    for (int i=0;i<n;i++) {
        for (int j : prefs[i]) {
            if (reachable[j][i]) {cout << j+1 << endl; break;}
        }
    }
}