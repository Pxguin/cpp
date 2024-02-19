#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fr;
    int n,b,k,light;
    fr.open("maxcross.in");
    vector<int> signals;
    
    fr >> n;fr >> k;fr >> b;
    for (int i = 0; i < n; i++) {
        signals.push_back(1);
    }
    for (int i = 0; i < b; i++) {
        fr >> light;
        signals[light-1] = 0;
    }

    int minimum = k;
    int broken = 0;
    for (int i = 0; i < k; i++) {
        if (signals[i] == 0) {
            broken++;
        }
    }
    if (broken < minimum) {
        minimum = broken;
    }
    for (int i = 1; i < n-k+1; i++) {
        if (signals[i-1] == 0) {
            broken--;
        }
        if (signals[i+k-1] == 0) {
            broken++;
        }
        if (broken < minimum) {
            minimum = broken;
        }
    }
    fr.close();
    ofstream fw;
    fw.open("maxcross.out");
    fw << minimum;
    fw.close();
}