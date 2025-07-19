#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)

const int N = 2e5, M = 2e5+1;
int n, m;
pair<int,int> g[N];

ll sum[2][2*M] = {0}; // counts sum of values
bool prop[2][2*M] = {false}; // lazy propagation
int cnt[2][2*M] = {0}; // counts amount of nonzero values

void build(int p, int cur=1, int l=0, int r=m/2) {
    if (l>r) {return;}
    if (l==r) {
        if (2*l+p>=m) {return;}
        cnt[p][cur] = 1; // defaults
        sum[p][cur] = 2*l+p;
    } else {
        int mid = (l+r)/2;
        build(p,2*cur,l,mid);
        build(p,2*cur+1,mid+1,r);

        cnt[p][cur] = cnt[p][2*cur]+cnt[p][2*cur+1];
        sum[p][cur] = sum[p][2*cur]+sum[p][2*cur+1];
    }
}
void push(int p, int cur, int l, int r) { // propagate to children
    if (prop[p][cur]) {
        if (l!=r) {prop[p][2*cur] = prop[p][2*cur+1] = true;}
        sum[p][cur] = cnt[p][cur] = 0;
        prop[p][cur] = false;
    }
}
void upd(int p, int ql, int qr, int cur=1, int l=0, int r=m/2) { // set all values in [ql,qr] to zero
    if (l>r) {return;}
    push(p,cur,l,r);
    if (ql>qr) {return;}

    if (ql==l && qr==r) {
        prop[p][cur] = true;
        push(p,cur,l,r);
    } else {
        int mid = (l+r)/2;
        upd(p,ql,min(mid,qr),2*cur,l,mid);
        upd(p,max(mid+1,ql),qr,2*cur+1,mid+1,r);

        cnt[p][cur] = cnt[p][2*cur]+cnt[p][2*cur+1];
        sum[p][cur] = sum[p][2*cur]+sum[p][2*cur+1];
    }
}
ll ans = 0, a;
ll cur_ans = 0, cur_cnt = 0;

void qry(int p, int sl, int sr, int ql, int qr=m/2, int cur=1, int l=0, int r=m/2) { // sum of [ql,qr] given that [sl,sr] are set to 0
    if (l>r) {return;}
    push(p,cur,l,r);
    if (ql>qr) {return;}

    if (ql==l && qr==r && sl==l && sr==r) {return;}
    if (ql==l && qr==r && (sl>sr || sr<ql || sl>qr)) { // only add to the answer when [l,r] is contained in [ql,qr] and is disjoint from [sl,sr]
        cur_cnt += cnt[p][cur];
        cur_ans += sum[p][cur];
        return;
    }
    int mid = (l+r)/2; // otherwise recurse
    qry(p,sl,min(sr,mid),ql,min(qr,mid),2*cur,l,mid);
    qry(p,max(sl,mid+1),sr,max(ql,mid+1),qr,2*cur+1,mid+1,r);

    cnt[p][cur] = cnt[p][2*cur]+cnt[p][2*cur+1];
    sum[p][cur] = sum[p][2*cur]+sum[p][2*cur+1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    a = m-1;

    for (int i=0;i<n;i++) {
        cin >> g[i].f >> g[i].s;
        --g[i].f; --g[i].s;
    }
    sort(g,g+n,[&](pair<int,int> c, pair<int,int> b) {return c.s<b.s;});

    memset(sum,0,sizeof(sum)); memset(cnt,0,sizeof(cnt));
    memset(prop,0,sizeof(prop));

    build(0); build(1);

    queue<int> set3; // set 3: satisfying r>a
    for (int i=n-1;i>=0;i--) {set3.push(i);}
    priority_queue<pair<int,int>> set2; // set 2: satisfying l<=a<=r
    multiset<int> set2_r[2]; // minimum r in set 2 (of both parities)
    // (implicit) set 1: satisfying a<l

    for (;a>=0;a--) {
        while (set3.size() && g[set3.front()].s==a) { // set 3 -> set 2
            set2.push({g[set3.front()].f,set3.front()});
            set2_r[g[set3.front()].s%2].insert(g[set3.front()].s);
            set3.pop();
        }
        while (set2.size() && g[set2.top().s].f>a) { // set 2 -> set 1
            int cur = set2.top().s; set2.pop();
            set2_r[g[cur].s%2].erase(set2_r[g[cur].s%2].find(g[cur].s));
            
            if ((g[cur].s-g[cur].f+1)%2==0) { // please delete [g[cur].s,m-1] (if r-l+1) is even
                upd(0,(g[cur].s+1)/2,(m-1)/2);
                upd(1,g[cur].s/2,(m-2)/2);
            }
            if (g[cur].f&1) { // delete all even positions in [g[cur].f,g[cur].s]
                upd(0,(g[cur].f+1)/2,g[cur].s/2);
            } else { // delete odd in [g[cur].f,g[cur].s]
                upd(1,g[cur].f/2,(g[cur].s-1)/2);
            }
        }

        if (set2.size()) { // only recompute if set 2 is nonempty (to deal with constraint that at least one garden has at least one fountain)
            int l = m+3, r = -3, lim_l = m+3, lim_r = -3;

            int mx = set2_r[0].size() ? *set2_r[0].rbegin() : 0; // max r in set 2
            if (set2_r[1].size()) {chmax(mx,*set2_r[1].rbegin());}
            if (mx!=a) { // all even (or odd) positions in [l,r] don't work
                l = a+1; r = mx;
            }
            if (set2_r[!(a%2)].size()) { // min r such that r-a+1 is even
                lim_l = *set2_r[!(a%2)].begin(); // all of [lim_l,m-1] doesn't work
                lim_r = m-1;
            }

            cur_cnt = cur_ans = 0;
            if (l%2) {
                qry(1, min(l,lim_l)/2,(max(lim_r,r)-1)/2, a/2); // delete odd from [min(l,lim_l),max(lim_r,r)]
                qry(0, (lim_l+1)/2,lim_r/2, (a+1)/2); // delete even from [lim_l,lim_r]
            } else {
                qry(0, (min(l,lim_l)+1)/2,max(lim_r,r)/2, (a+1)/2); // delete even from [min(l,lim_l),max(lim_r,r)]
                qry(1, lim_l/2,(lim_r-1)/2, a/2); // delete odd from [lim_l,lim_r]
            }
        }
        ans += cur_ans-cur_cnt*(a-1); // add to answer
    }

    cout << ans << '\n'; // holy
}