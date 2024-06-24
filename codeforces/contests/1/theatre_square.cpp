#include <iostream>
using namespace std;
 
int main() {
    long n, m, a; cin >> n >> m >> a;
    long long ans = ((n+a-1)/a); ans *= ((m+a-1)/a);
    cout << ans;
}