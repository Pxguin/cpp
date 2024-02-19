#include <iostream>
using namespace std;

int main() {
    int n; cin >> n; int ans; int temp;
    string input = "";
    for (int i=0;i<n;i++) {
        cin >> input;
        ans = -1;
        for (int i=1;i<input.length()-1;i++) {
            temp = -1;
            if (input[i] == 'O') {temp++;
                if (input[i-1] == 'M') {temp++;}
                if (input[i+1] == 'O') {temp++;}
            }
            ans = max(ans,temp);
        }
        if (ans==-1) {cout << -1;} else {cout << input.length()-ans-1;} cout << endl;
    }
}