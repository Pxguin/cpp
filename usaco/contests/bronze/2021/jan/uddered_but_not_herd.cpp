#include <iostream>

using namespace std;

int main() {
    char alph[26];
    cin >> alph;

    string str;

    cin >> str;

    int c_index = 0;
    int times = 1;
    int t_index;
    char letter;
    for (int i = 0; i < str.size(); i++) {
        letter = str[i];
        for (int j = 0; j < 26; j++) {
            if (alph[j] == letter) {
                t_index = j;
                break;
            }
        }
        //cout << t_index << "\n";
        if (t_index <= c_index) {
            times++;
        }
        c_index = t_index;
    }
    cout << times;
    
}