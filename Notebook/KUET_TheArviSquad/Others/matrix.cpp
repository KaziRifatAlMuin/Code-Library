#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const int N = 2e5 + 9, mod = 998244353;

class Matrix {
public:
    vector<vector<ll>> mat;
    int r, c;
    Matrix() {
        mat.clear();
        r = 0;
        c = 0;
    }
    Matrix(int n, int m) {
        r = n;
        c = m;
        mat.assign(n + 1, vector<ll> (m + 1, 0));
    }
    Matrix make_identity() {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                this->mat[i][j] = (i == j);
            }
        }
        return *this;
    }
    Matrix expo(Matrix A, int k) {
        auto [r, c] = A.get_dimension();
        Matrix res(r, c);
        res.make_identity();
        while(k) {
            if(k & 1) {
                res = res * A;
            }
            A = A * A;
            k >>= 1;
        }
        return res;
    }
    pair<int, int> get_dimension() {
        return {r, c};
    }
    friend Matrix operator * (Matrix &A, Matrix &B) {
        auto [r1, c1] = A.get_dimension();
        auto [r2, c2] = B.get_dimension();
        assert(c1 == r2);
        Matrix res(r1, c2);
        for(int i = 1; i <= r1; i++) {
            for(int j = 1; j <= c2; j++) {
                ll sum = 0;
                for(int k = 1; k <= c1; k++) {
                    sum += (A.mat[i][k] % mod * B.mat[k][j] % mod) % mod;
                }
                res.mat[i][j] = sum;
            }
        }
        return res;
    }
    void take_input() {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cin >> mat[i][j];
            }
        }
    }
    void display() {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};