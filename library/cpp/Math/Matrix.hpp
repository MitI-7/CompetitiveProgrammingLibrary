#include <vector>
#include <cassert>
#include <iostream>
#include <numeric>


template <typename T=long long> class Matrix {
public:
    int m;  // 行
    int n;  // 列
    std::vector<std::vector<T>> matrix;

    Matrix(std::vector<std::vector<T>> matrix) : matrix(matrix) {
        this->m = matrix.size();
        this->n = matrix[0].size();
    }

    // m行n列の行列
    Matrix(int m, int n) : m(m), n(n) {
        this->matrix = std::vector<std::vector<T>>(m, std::vector<T>(n));
    }

    // m行m列の単位行列を生成
    static Matrix identity_matrix(int m) {
        auto a = Matrix(m, m);
        for (int i = 0; i < m; ++i) {
            a.matrix[i][i] = 1;
        }
        return a;
    }

    // matrix * a;
    void multiple(const Matrix &a, const long long mod = 0LL) {
        assert(this->n == a.m);
        Matrix b = Matrix::matrix_multiple(*this, a, mod);
        this->m = b.m;
        this->n = b.n;
        this->matrix = b.matrix;
    }

    // a * b
    static Matrix matrix_multiple(const Matrix &a, const Matrix &b, const long long mod = 0LL) {
        assert(a.n == b.m);
        Matrix c(a.m, b.n);
        for (int i = 0; i < a.m; ++i) {
            for (int k = 0; k < a.n; ++k) {
                for (int j = 0; j < b.n; ++j) {
                    c.matrix[i][j] = c.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j];
                    if (mod != 0) {
                        c.matrix[i][j] %= mod;
                    }
                }
            }
        }

        return c;
    }

    // matrix^k
    void pow(const long long k, const long long mod = 0LL) {
        assert(this->m == this->n);
        auto a = Matrix::matrix_pow(*this, k, mod);
        this->m = a.m;
        this->n = a.n;
        this->matrix = a.matrix;
    }

    // a^k
    static Matrix matrix_pow(const Matrix &a, long long k, const long long mod = 0LL) {
        assert(a.m == a.n);
        const int n = a.m;

        Matrix b = Matrix::identity_matrix(n);
        while (k > 0) {
            if (k % 2 == 1) {
                b = Matrix::matrix_multiple(b, a, mod);
            }
            a = Matrix::matrix_multiple(a, a, mod);
            k /= 2;
        }
        return b;
    }

    // 行列式 O(n^3)
    double determinant() const {
        assert(this->m == this->n);

        std::vector<std::vector<double>> mat = this->matrix;
        std::vector<int> ri(n);
        std::iota(ri.begin(), ri.end(), 0);

        double det = 1.0;
        for (int p = 1 ; p <= n - 1; p++) {
            for (int i = p + 1 ; i <= n; i++) {
                if (std::abs(mat[ri[i - 1]][p - 1]) > std::abs(mat[ri[p - 1]][p - 1])) {
                    int t = ri[p - 1];
                    ri[p - 1] = ri[i - 1];
                    ri[i - 1] = t;
                    det = -det;
                }
            }
            if (mat[ri[p - 1]][p - 1] == 0) {
                return false;
            }

            det = det * mat[ri[p - 1]][p - 1];

            for (int i = p + 1 ; i <= n; i++) {
                mat[ri[i - 1]][p - 1] /= mat[ri[p - 1]][p - 1];

                for (int j = p + 1 ; j <= n; j++) {
                    mat[ri[i - 1]][j - 1] -= mat[ri[i - 1]][p - 1] * mat[ri[p - 1]][j - 1];
                }
            }
        }

        return det * mat[ri[n - 1]][n - 1];
    }

    // 整数になるとわかっているときの行列式O(n^3)
    long long determinant2() const {
        if (this->m != this->n) {
            return -1;
        }

        std::vector<std::vector<long long>> mat(this->n, std::vector<long long>(this->n, 0));
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                mat[i][j] = this->matrix[i][j];
            }
        }

        int k = 0;
        long long c = 1;
        long long s = 1;

        while (k < this->n - 1) {
            int p = mat[k][k];
            if (p == 0) {
                auto i = k;
                while (i < this->n and mat[i][k] == 0) {
                    ++i;
                }
                if (i >= this->n) {
                    return 0;
                }

                for (int j = k; j < this->n; ++j) {
                    const auto tmp = mat[i][j];
                    mat[i][j] = mat[k][j];
                    mat[k][j] = tmp;
                }

                s *= -1;
                p = mat[k][k];
            }

            for (int i = k + 1; i < this->n; ++i) {
                for (int j = k + 1; j < this->n; ++j) {
                    const auto t = p * mat[i][j] - mat[i][k] * mat[k][j];
                    mat[i][j] = t / c;
                }
            }
            c = p;
            k++;
        }

        return s * mat[n - 1][n - 1];
    }

    // modをとる行列式(O(N^3))
    long long determinant_mod(long long mod) const {
        if (this->m != this->n) {
            return -1;
        }

        std::vector<std::vector<long long>> mat(this->n, std::vector<long long>(this->n, 0));
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                mat[i][j] = this->matrix[i][j];
            }
        }

        long long ans = 1;
        bool flag;

        for (int i = 0; i < this->n; ++i) {
            if (not mat[i][i]) {
                flag = false;
                for (int j = i + 1; j < this->n; ++j) {
                    if (mat[j][i]) {
                        flag = true;
                        for (int k = i; k < this->n; ++k) {
                            std::swap(mat[i][k], mat[j][k]);
                        }
                        ans = -ans;
                        break;
                    }
                }
                if (not flag) {
                    return 0;
                }
            }

            for (int j = i + 1; j < this->n; ++j) {
                while (mat[j][i]) {
                    long long t = mat[i][i] / mat[j][i];
                    for (int k = i; k < n; ++k) {
                        mat[i][k] -= t * mat[j][k];
                        mat[i][k] %= mod;
                        std::swap(mat[i][k], mat[j][k]);
                    }
                    ans = -ans;
                }
            }
            ans *= mat[i][i];
            ans %= mod;
        }

        return (ans + mod) % mod;
    }

    void show() const {
        for (int i = 0; i < this->m; ++i) {
            for (int j = 0; j < this->n; ++j) {
                if (j != 0) {
                    std::cout << " ";
                }
                std::cout << this->matrix[i][j];
            }
            std::cout << std::endl;
        }
    }
};
