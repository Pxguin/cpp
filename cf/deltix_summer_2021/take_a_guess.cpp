#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int sum(int a, int b) {
    cout << "or " << a << " " << b << endl; 
    cout << "and " << a << " " << b << endl;
    int and_; int or_; cin >> or_ >> and_;
    
    /*int xor_ = ~and_ & or_;
    int res = 2*and_ + xor_;*/
    //int xor = or_-and_;
    int res = or_+and_;
    
    return res;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    
    vector<int> v;
    long long ab = sum(1, 2);
    long long bc = sum(2, 3);
    long long ca = sum(3, 1);
    long long a = (ab+bc+ca)/2-bc;
    int b = ab-a; int c = bc-b;
    v.push_back((int)a); v.push_back(b); v.push_back(c);
    
    for (int i=4;i<n+1;i++) {
        int x = sum(i-1, i)-v.back();
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << "finish " << v[k-1] << endl;
}