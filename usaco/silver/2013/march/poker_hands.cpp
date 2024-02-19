#include <iostream>

using namespace std;

int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;cin>>n;
    int cards[n];
    for (int i=0;i<n;i++) {cin>>cards[i];}

    int prev_break=0; long ans=0; int maxcard=0; int card;
    int i=0;
    int start=0;

    while (true) {
        //card = cards[i];
        if (cards[i] != 0) {
            start=i;
            while (i != n) {
                if (cards[i] == 0) {
                    break;
                }
                i++;
            }
            for (int j=start;j<i;j++) {
                cards[j] = cards[j]-1;
            }
            ans++;
            i=0;
            continue;
        }

        i++;
        if (i==n) {break;}
    }
    cout << ans;
}