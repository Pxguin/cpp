#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,q;
    freopen("bcount.in","r",stdin);freopen("bcount.out","w",stdout);
    cin >> n >> q;
    int input;
    int g=0,h=0,j=0;
    vector<int> g1={0},h1={0},j1={0};
    int q1,q2;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == 1) {
            h++;
        } else if (input == 2) {
            g++;
        } else {
            j++;
        }
        g1.push_back(g);
        h1.push_back(h);
        j1.push_back(j);
    } 
    for (int i = 0; i < q; i++) {
        cin >> q1 >> q2;
        cout << h1[q2]-h1[q1-1] << " " << g1[q2]-g1[q1-1] << " " << j1[q2]-j1[q1-1] << endl;
    }
    fclose(stdin);fclose(stdout);
}