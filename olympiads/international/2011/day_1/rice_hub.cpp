#include <bits/stdc++.h>
#include "ricehub.h"
using namespace std;

#define ll long long

const int MAX_N = 1e5;
ll ps[MAX_N+1] = {0};

int besthub(int r, int l, int x[], ll b) {
    for (int i=0;i<r;i++) {ps[i+1] = ps[i]+x[i];}
    int ans = 0;
    for (int i=0,ptr=0;i<r;i++) {
        while (ptr+1<r) { // two pointers
            ptr++;
            ll med = (i+ptr)/2;
            ll cost = ps[ptr+1]-ps[med]-(ptr-med+1)*x[med] + (med-i)*x[med]-ps[med]+ps[i]; // cost of this range
            if (cost>b) {ptr--; break;} // make sure it doesn't exceed B
        }
        ans = max(ans,ptr-i+1);
    }
    return ans;
}