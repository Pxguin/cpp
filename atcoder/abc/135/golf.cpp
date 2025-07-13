#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define vec vector

int k, x, y, cx = 0, cy = 0;
vec<pair<int,int>> ans;
void move2(int x, int y) { // get the vector (x,y) in two moves
    assert(x+y<=2*k); // preconditions
    assert(x<=y); // also, x,y>=0

    int a = k-(y-x)/2, b = k-a; // construction: (a,b) is first move, (c,d) is second
    int c = x-a, d = k-abs(c);
    assert(a+c==x);
    assert(b+d==y);

    ans.pb({a,b});
    ans.pb({c,d});
}

void move(int dx, int dy) { // move exactly dx and dy in at most two moves (no precondition except |dx|+|dy|<=2k)
    cx += dx; cy += dy;
    bool inv[3] = {false}; // just transform to achieve dx,dy>=0 and dx<=dy
    if (dx<0) {inv[0] = true;} // y=0 reflection
    if (dy<0) {inv[1] = true;} // x=0 reflection
    dx = abs(dx); dy = abs(dy);
    if (dx>dy) { // y=x reflection
        inv[2] = true;
        swap(dx,dy);
    }

    int len = 2;
    if (dx+dy==k) { // special case: it can be done in one move only
        len = 1;
        ans.pb({dx,dy});
    } else { // otherwise do it in two moves
        move2(dx,dy);
    }
    for (int i=ans.size()-len;i<ans.size();i++) { // un-transform all moves
        if (inv[2]) {swap(ans[i].f,ans[i].s);}
        if (inv[0]) {ans[i].f *= -1;}
        if (inv[1]) {ans[i].s *= -1;}
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> k >> x >> y;
    bool inv[2] = {false}; // transform to get x,y>=0
    if (x<0) {inv[0] = true;}
    if (y<0) {inv[1] = true;}
    x = abs(x); y = abs(y);

    if (k%2==0 && (x+y)%2) {cout << -1; return 0;} // only fail case

    while (x-cx+y-cy>2*k) { // move orthogonally until manhattan dist to (x,y) <= 2k
        if (x-cx>=k) {
            move(k,0);
        } else {
            move(0,k);
        }
    }
    if ((x-cx+y-cy)%2) { // make sure parity of dist is even
        if (x-cx+y-cy!=k) { // if it's odd, then make an arbitrary move (but maintain that dist<=2k)
            if (x-cx>y-cy) {
                move(k,0);
            } else {
                move(0,k);
            }
        }
    } move(x-cx,y-cy); // move to (x,y) in at most two moves

    cx = 0; cy = 0;
    cout << ans.size() << '\n';
    for (int i=0;i<ans.size();i++) { // un-transform moves
        if (inv[0]) {ans[i].f *= -1;}
        if (inv[1]) {ans[i].s *= -1;}
        cx += ans[i].f;
        cy += ans[i].s;
        cout << cx << ' ' << cy << '\n';
    }
}