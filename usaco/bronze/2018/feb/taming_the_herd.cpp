#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    int n;
    int temp;
    vector<int> log;
    ifstream fr;
    bool fail = false;

    int min_break = 0;
    int max_break = 0;
    
    fr.open("taming.in");
    fr >> n;

    for (int i = 0; i < n; i++) {
        fr >> temp;
        log.push_back(temp);

        log[0] = 0;
        
        if (temp > 0) {
            for (int i = log.size()-temp; i < log.size(); i++) {
                if (log[i] == 0) {
                    fail = true;
                    break;
                }
                log[i] = -2;
                log[log.size()-temp-1] = 0;
            }
        }
        if (fail) {
            break;
        }
    }
    ofstream fw;
    fw.open("taming.out");

    if (!fail) {
        for (int i = 0; i < n; i++) {
            if (log[i] == 0) {
                min_break++;
                max_break++;
            } else if (log[i] == -1) {
                max_break++;
            }
        }
        fw << min_break << " " << max_break;
    } else {
        fw << -1;
    }
    fw.close();
    fr.close();
    
}