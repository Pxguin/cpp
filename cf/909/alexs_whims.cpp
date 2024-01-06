#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> b1; vector<int> b2;
    for (int i=0;i<n-1;i++) {
        b1.push_back(i);
        cout << i+1 << " " << i+2 << "\n";
    }
    b1.push_back(n-1);
    b2.push_back(1);
    
    int d;
    for (int i=0;i<q;i++) {
        cin >> d;
        if (d == b1.size()-1) {
            cout << "-1 -1 -1" << "\n";
            
        } else if (d > b1.size()-1) {
            vector<int> move(b2.end()-(d-b1.size()+1),b2.end());
            cout << move.front()+1 << " " << b2[b2.size()-move.size()-1]+1 << " " << b1.back()+1 << "\n";
            for (int node : move) {
                b2.pop_back();
                b1.push_back(node);
            }
            
        } else {
            vector<int> move(b1.begin()+(d+1),b1.end());
            cout << move.front()+1 << " " << b1[d]+1 << " " << b2.back()+1 << "\n";
            for (int node : move) {
                b1.pop_back();
                b2.push_back(node);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;//t--;
    while (t--) {solve();}
}