#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int mod = 1e9+7, l2 = 18;

struct Matrix {
    vec<vec<ll>> mat;
    Matrix() {}
    Matrix(int n) {
        mat = vec<vec<ll>>(n,vec<ll>(n,0));
        for (int i=0;i<n;i++) {mat[i][i] = 1;}
    }
    Matrix(int n, int m) {mat = vec<vec<ll>>(n,vec<ll>(m,0));}
    void extend() {
        for (int i=0;i<mat.size();i++) {mat[i].pb(0);}
        mat.pb(vec<ll>(mat.size()+1,0));
        mat[mat.size()-1][mat.size()-1] = 1;
    }
    void print() {
        for (int i=0;i<mat.size();i++) {
            for (int j=0;j<mat.size();j++) {cout << mat[i][j] << ' ';}
            cout << '\n';
        } cout << '\n';
    }
};
Matrix operator*(const Matrix& a, const Matrix& b) {
    int n = a.mat.size();
    Matrix c(n,n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<n;k++) {
               c.mat[i][j] = (c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
            }
        }
    } return c;
}
void operator*=(Matrix& a, const Matrix& b) {a = a*b;}


stack<Matrix> todo;
stack<int> reps;
int var_cnt = 1;
map<string,int> idx;

Matrix exp(Matrix a, int b) {
    Matrix res(var_cnt);
    for (int i=0;i<l2;i++) {
        if ((1<<i)&b) {res *= a;}
        a *= a;
    } return res;
}

bool is_var(const string& s) {
    return ('a'<=s[0] && s[0]<='z');
}
bool is_literal(const string& s) {
    return ('0'<=s[0] && s[0]<='9');
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cowbasic.in","r",stdin);
    freopen("cowbasic.out","w",stdout);

    string s;

    todo.push(Matrix(var_cnt)); reps.push(1); // todo stores all current loops
    string last;

    while (cin >> s) {
        Matrix& m = todo.top();
        if (is_var(s)) { // variable
            if (!idx.count(s)) { // new variable?
                m.extend();
                idx[s] = var_cnt++;
            }
            vec<ll> new_row(var_cnt); // update the matrix for the current loop
            int v = idx[s];
            getline(cin,s);
            stringstream ss(s);
            while (ss >> s) {
                if (is_var(s)) {
                    // expand linear combination (could be done easier via matrix mult)
                    int id = idx[s];
                    for (int j=0;j<var_cnt;j++) {
                        new_row[j] = (new_row[j] + m.mat[id][j])%mod;
                    }
                } else if (is_literal(s)) {
                    new_row[0] = (new_row[0] + stoi(s))%mod;
                }
            }
            m.mat[v] = new_row;
        } else if (is_literal(s)) { // loop begin
            reps.push(stoi(s));
            todo.push(Matrix(var_cnt));

            cin >> s; cin >> s;
            
        } else if (s=="}") { // end loop

            Matrix loop = exp(m,reps.top()); // get mapping for whole loop
            todo.pop(); reps.pop();

            Matrix new_mat(var_cnt,var_cnt);
            Matrix& old_mat = todo.top();
            while (old_mat.mat.size()<var_cnt) {old_mat.extend();}

            for (int i=0;i<var_cnt;i++) { // combine mapping into the next loop
                for (int j=0;j<var_cnt;j++) {
                    for (int k=0;k<var_cnt;k++) {
                        new_mat.mat[i][k] = (new_mat.mat[i][k] + loop.mat[i][j]*old_mat.mat[j][k])%mod;
                    }
                }
            }
            old_mat = new_mat;

        } else { // return
            cin >> s;
            cout << m.mat[idx[s]][0] << '\n';
        }
    }
}