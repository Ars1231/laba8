#include <iostream>
#include <stdexcept>
using namespace std;

struct Matrix {
    int** data_ = nullptr;
    size_t n_ = 0u;
    size_t m_ = 0u;
};

void Construct(Matrix& out, size_t n, size_t m) {
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int*[m];
    for (size_t i = 0; i < m; ++i) {
        out.data_[i] = new int[n]();
    }
}

void Destruct(Matrix& in) {
    for (size_t i = 0; i < in.m_; ++i) {
        delete[] in.data_[i];
    }
    delete[] in.data_;
    in.data_ = nullptr;
    in.n_ = 0;
    in.m_ = 0;
}

Matrix Copy(const Matrix& matrix) {
    Matrix copy;
    Construct(copy, matrix.n_, matrix.m_);
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            copy.data_[i][j] = matrix.data_[i][j];
        }
    }
    return copy;
}

Matrix Add(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) {
        return Matrix{};
    }
    Matrix result;
    Construct(result, a.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < a.n_; ++j) {
            result.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return result;
}

Matrix Sub(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) {
        return Matrix{};
    }
    Matrix result;
    Construct(result, a.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < a.n_; ++j) {
            result.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return result;
}

Matrix Mult(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.m_) {
        return Matrix{};
    }
    Matrix result;
    Construct(result, b.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < b.n_; ++j) {
            result.data_[i][j] = 0;
            for (size_t k = 0; k < a.n_; ++k) {
                result.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
    return result;
}

void Transposition(Matrix& matrix) {
    Matrix transposed;
    Construct(transposed, matrix.m_, matrix.n_);
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            transposed.data_[j][i] = matrix.data_[i][j];
        }
    }
    Destruct(matrix);
    matrix = transposed;
}

bool operator==(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) {
        return false;
    }

    for (size_t i = 0; i < a.m_; ++i) {

        for (size_t j = 0; j < a.n_; ++j) {
            if (a.data_[i][j] != b.data_[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void cout_matrix(const Matrix& a) {
    for (size_t i = 0; i < a.m_; ++i) {
        for (size_t j = 0; j < a.n_; ++j) {
            cout << a.data_[i][j] << ' ';
        }
        cout << '\n';
    }
    cout<<endl;
}

int main() {
    Matrix matrixA, matrixB, matrixC;
    Construct(matrixA, 3, 3);
    Construct(matrixB, 3, 3);

    for (size_t i = 0; i < matrixA.m_; ++i) {
        for (size_t j = 0; j < matrixA.n_; ++j) {
            matrixA.data_[i][j] = i + j;
            matrixB.data_[i][j] = (i + j) * i;
        }
    }
    int x;
    cin >> x;
    while (true) {
        switch (x) {
            case 1:
                matrixC = Copy(matrixA);
                cout_matrix(matrixA);
                cout_matrix(matrixB);
                cout_matrix(matrixC);
                Destruct(matrixA);
                Destruct(matrixB);
                Destruct(matrixC);
                abort();
            case 2:
                matrixC = Add(matrixA, matrixB);
                cout_matrix(matrixA);
                cout_matrix(matrixB);
                cout_matrix(matrixC);
                Destruct(matrixA);
                Destruct(matrixB);
                Destruct(matrixC);
                abort();
            case 3:
                matrixC = Sub(matrixA, matrixB);
                cout_matrix(matrixA);
                cout_matrix(matrixB);
                cout_matrix(matrixC);
                Destruct(matrixA);
                Destruct(matrixB);
                Destruct(matrixC);
                abort();
            case 4:
                matrixC = Mult(matrixA, matrixB);
                cout_matrix(matrixA);
                cout_matrix(matrixB);
                cout_matrix(matrixC);
                Destruct(matrixA);
                Destruct(matrixB);
                Destruct(matrixC);
                abort();
            case 5:
                cout<<operator==(matrixA, matrixB);
                abort();
            case 0:
                break;
        }
    }
    return 0;
}
