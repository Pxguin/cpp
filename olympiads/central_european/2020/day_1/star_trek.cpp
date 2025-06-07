#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 1e5;
vec<int> adj[MAX_N];
int state_down[MAX_N], state_up[MAX_N], state[MAX_N];
ll L = 0; // amount of losing nodes
ll S_L = 0, S_W = 0;
int rt = 0;

void dfs_state_down(int cur) { // for each node: counts amount of children that are losing
    for (int x : adj[cur]) {
        adj[x].erase(find(all(adj[x]),cur));
        dfs_state_down(x);
        state_down[cur] += !state_down[x];
    }
}
void dfs_state_up(int cur) { // for each node: counts if the complement of parent's subtree is losing
    state[cur] = (state_up[cur]+state_down[cur]); // this node is winning iff at least one adjacent node is losing
    L += !state[cur];
    for (int x : adj[cur]) {
        state_up[x] = !(state_up[cur]+(state_down[cur]-!state_down[x]));
        dfs_state_up(x);
    }
}

int lose_down[MAX_N], lose_up[MAX_N], lose[MAX_N];

void dfs_lose_down(int cur) { // for each node, when restricted to its subtree: calculate amount of losing nodes, then when change states, propagates a change in this node's state
    lose_down[cur] = !state_down[cur];
    for (int x : adj[cur]) {
        dfs_lose_down(x);
        if (state_down[cur]==1 && !state_down[x]) { // casework
            lose_down[cur] += lose_down[x];
        } else if (!state_down[cur]) {
            lose_down[cur] += lose_down[x];
        }
    }
}
void dfs_lose_up(int cur) { // same thing as lose_down, but restrict it to the complement of the subtree
    lose_up[cur] += !state_up[cur]; // base cases

    lose[cur] = !state[cur];
    if (state[cur]==1) { // combining answers for inside and outside subtree
        for (int x : adj[cur]) { // if node is winning state, then can change it to losing if exactly one adjacent neighbour is losing
            if (!state_down[x]) {
                lose[cur] += lose_down[x];
            } // find that neighbour, and update
        }
        if (state_up[cur]) {lose[cur] += lose_up[cur];}
    } else if (!state[cur]) { // if node is losing, then all adjacent are winning: can change any neighbour's state
        for (int x : adj[cur]) {lose[cur] += lose_down[x];}
        lose[cur] += lose_up[cur]-1; // so sum up answers for all neighbours
    }
    if (state[cur]) {S_W += lose[cur];} // sum of lose for winning states
    else {S_L += lose[cur];} // sum of lose for losing states

    int sum1 = 0, sum2 = 0;
    for (int x : adj[cur]) { // to speed up dp transition to children
        if (state_down[x]) {sum1 += lose_down[x];}
        else {sum2 += lose_down[x];}
    }

    for (int x : adj[cur]) {
        if (state_up[x]) { // casework (follows similar logic as calculating lose[cur])
            lose_up[x] = sum1+lose_up[cur]-(state_down[x] ? lose_down[x] : 0);
        } else {
            if (state_up[cur]+state_down[cur]-!state_down[x]==1) {
                lose_up[x] = (state_up[cur] ? lose_up[cur] : sum2-(!state_down[x] ? lose_down[x] : 0));
            }
        }
        dfs_lose_up(x);
    }
}

const ll mod = 1e9+7;
ll add(ll a, ll b) {ll c = (a+b)%mod; if (c<0) {c+=mod;} return c;}
ll mul(ll a, ll b) {return a*b%mod;}
ll exp(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b&1) {c = mul(c,a);}
        a = mul(a,a); b /= 2;
    } return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; ll d; cin >> n >> d;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for (int i=0;i<n;i++) {if (adj[i].size()>1) {rt = i;}}

    memset(state_down,0,sizeof(state_down));
    state_up[rt] = 0;
    dfs_state_down(rt); // rerooting: is each node losing or winning
    dfs_state_up(rt);

    dfs_lose_down(rt);
    dfs_lose_up(rt);

    d--; // now use geometric series to calculate the answer for the first parallel universe
    ll S = add(S_W,-S_L), R = mul(mul(n,n),exp(S,mod-2));
    ll geosum = mul(mul(L,mul(n,n)),exp(S,d-1)) * add(1,-exp(R,d)) %mod * exp(add(1,-R),mod-2) %mod;

    L = mul(exp(S,d),L);
    L = add(L,geosum);
    ll tot = exp(mul(n,n),d+1);
    
    ll ans;
    if (state[0]) {ans = add(tot,-mul(lose[0],L));} // now calculate the answer for node 1 in the original universe
    else {ans = mul(lose[0],L);}

    cout << ans << '\n';
}