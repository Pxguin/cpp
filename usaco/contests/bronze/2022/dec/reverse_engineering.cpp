#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> zero;
unordered_set<string> one;
int n;

bool check(unordered_set<string> &z, unordered_set<string> &o) {
    unordered_set<string> copy = o;
    for (int i=0;i<n;i++) {
        bool works = true;
        char goal = (*z.begin())[i];
        for (auto &input: z) {
            if (input[i] != goal) {works = false; break;}
        }
        if (works) {
            works = false;
            for (auto &input : copy) {
                if (input[i] != goal) {works = true; o.erase(input);}
            }
            if (works) {return true;}
        }
    }
    return false;
}

int main() {
    int t; cin >> t;

    string input; int output;

    for (int c=0;c<t;c++) {
        int m; cin >> n >> m;
        zero.clear(); one.clear();
        for (int i = 0; i < m; i++) {
            cin.ignore();
            getline(cin, input, ' ');
            cin >> output;
            if (output == 0) { zero.insert(input); }
            else { one.insert(input); }
        }

        bool ans = true;
        while (!zero.empty() && !one.empty()) {
            bool check1 = check(zero,one);
            if (one.empty()) {break;}
            bool check2 = check(one,zero);
            if (zero.empty()) {break;}
            if (!(check1 || check2)) {
                ans = false;
                break;
            }
        }

        if (ans) { cout << "OK"; } else { cout << "LIE"; }
        cout << "\n";
    }
}