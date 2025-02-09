#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    char x; cin >> x;
    cout << (x=='a'||x=='e'||x=='i'||x=='o'||x=='u' ? "vowel" : "consonant") << '\n';
}