#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("highcard.in","r",stdin);freopen("highcard.out","w",stdout);
    int n; cin >> n;
    int cards[n+1];
    for (int i=0;i<n;i++) {cin>>cards[i];}
    int elsie=0,have=0,wins=0,temp;
    sort(cards,cards+n);
    cards[n]=2*n+1;
    for (int i=0;i<n;i++) {
        elsie++;
        have=cards[i+1]-cards[i]-1;
        temp=min(have,elsie);
        wins += temp;
        elsie -= temp;
    }
    cout << wins;
}