#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int odd = 0;
    int even = 0;
    int temp;
    int diff;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    diff = odd-even;
    if (diff > 0) {
        odd -= diff;
        if (diff % 3 == 0) {
            cout << odd+even+diff/3*2;
        } else if (diff % 3 == 1) {
            cout << odd+even+(diff-1)/3*2-1;
        } else {
            cout << odd+even+(diff-2)/3*2+1;
        }
    } else if (diff < 0) {
        cout << odd*2+1;
    } else {
        cout << odd+even;
    }
}