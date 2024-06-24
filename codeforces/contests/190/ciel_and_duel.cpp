#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ja; // jiro atk
vector<int> jd; // jiro def
vector<int> ca; // ciel atk
int ans1 = 0; // scenario 1
int ans2 = 0; // scenario 2
vector<bool> vis;
int n, m;

void scen1() {
    int p1 = m-1;
    for (int card : jd) {
        while (ca[p1] <= card || vis[p1]) {
            p1--;
            if (p1 < 0) {return;}
        }
        vis[p1] = true;
    }
    p1 = 0;

    for (int card : ja) {
        while (vis[p1]) {
            p1++;
            if (p1 >= m) {return;}
        } if (ca[p1] < card) {return;}
        ans1 += ca[p1]-card;
        vis[p1] = true;
    }

    while (p1 < m) {
        if (!vis[p1]) {ans1 += ca[p1];}
        p1++;
    }
}

void scen2() {
    int p1 = 0;
    for (int card : ja) {
        if (p1 >= m || ca[p1] < card) {return;}
        ans2 += ca[p1]-card;
        p1++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    string type; int str;
    for (int i=0;i<n;i++) {
        cin >> type >> str;
        if (type == "ATK") {ja.push_back(str);}
        else (jd.push_back(str));
    }
    for (int i=0;i<m;i++) {
        cin >> str; ca.push_back(str);
    }
    sort(ca.begin(), ca.end(), greater<>());
    sort(ja.begin(), ja.end(), greater<>());
    sort(jd.begin(), jd.end());

    for (int i=0;i<m;i++) {vis.push_back(false);}

    if (m > n) {
        scen1();
    }
    sort(ja.begin(), ja.end());
    scen2();
    cout << max(ans1, ans2) << "\n";
}
