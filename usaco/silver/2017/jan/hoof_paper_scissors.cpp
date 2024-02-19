#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("hps.in","r",stdin);freopen("hps.out","w",stdout);
    int n; char m; cin >> n;
    vector<int> h = {0}; vector<int> p = {0}; vector<int> s = {0};
    for (int i = 0; i < n; i++) {
        cin >> m;
        h.push_back(h[i]);p.push_back(p[i]);s.push_back(s[i]);
        if (m == 'H') {h[i+1] = h[i+1]+1;}
        else if (m == 'P') {p[i+1] = p[i+1]+1;}
        else {s[i+1] = s[i+1]+1;}
    }

    int lower; int upper; int max2=0;

    for (int i = 0; i < n+1; i++) {
        lower = max(max(h[i],s[i]),p[i]);
        upper = max(max(h[n]-h[i],s[n]-s[i]),p[n]-p[i]);
        max2 = max(upper+lower,max2);
    }
    cout << max2;
    fclose(stdin); fclose(stdout);
}