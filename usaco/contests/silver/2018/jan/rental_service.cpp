#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rental.in","r",stdin);freopen("rental.out","w",stdout);
    int n, m, r; cin >> n >> m >> r;
    long milk_values[n]; pair<long,long> offers[m]; long rentals[r];
    for (int i=0;i<n;i++) {cin>>milk_values[i];}
    for (int i=0;i<m;i++) {cin>>offers[i].second>>offers[i].first;}
    for (int i=0;i<r;i++) {cin>>rentals[i];}

    sort(milk_values,milk_values+n,greater<>()); // care more about greater milk values/offers/rentals
    sort(offers,offers+m,greater<>());
    sort(rentals,rentals+r,greater<>());

    long gallons_left = offers[0].second, offer_val = offers[0].first, current_offer = 0;
    long rental_ptr = 0;
    long ans = 0;
    long cent_values[n]; fill(cent_values, cent_values+n, 0);
    long cval, mval;

    // pretend that all cows are going to be milked - calculate milk profit for every cow
    for (int i=0;i<n;i++) {
        mval = milk_values[i];
        cval = 0;
        while (mval > 0 && current_offer < m) {
            if (gallons_left > mval) {
                cval += mval * offer_val;
                gallons_left -= mval;
                mval = 0;
            }
            else {
                cval += (gallons_left) * offer_val;
                mval -= gallons_left;
                current_offer++;
                offer_val = offers[current_offer].first;
                gallons_left = offers[current_offer].second;
            }
        }
        cent_values[i] = cval; ans += cval;
        if (current_offer >= m) {break;}
    }

    // compare bottom cent values with rental values - sell ones that produce less than the current top rental
    sort(cent_values,cent_values+n);
    for (int i=0;i<n;i++) {
        if (cent_values[i] < rentals[rental_ptr]) {
            ans += rentals[rental_ptr] - cent_values[i];
            rental_ptr++;
            if (rental_ptr >= r) {break;}
        } else {break;}
    }

    cout << ans;
}