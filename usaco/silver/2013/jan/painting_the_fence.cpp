#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<pair<int,int>> move;
    freopen("paint.in","r",stdin);freopen("paint.out","w",stdout);
    int n; int n1; char dir; int pos = 0; int prev=0;
    int k; int layers = 0; int ans = 0; 
    cin >> n >> k;
    
    for (int i=0; i<n; i++) {
        cin >> n1 >> dir; 
        if (dir=='R') {pos+=n1;move.insert({pos-n1,1});move.insert({pos,0});} 
        else {pos-=n1;move.insert({pos,1});move.insert({pos+n1,0});}
    }
    
    for (pair<int,int> i : move) {
        if (i.second == 0) {layers--; if (layers==k-1) {ans+=i.first-prev;}} 
        else {layers++;if (layers==k) {prev=i.first;}}
    }
    cout << ans;
    fclose(stdin);fclose(stdout);
}