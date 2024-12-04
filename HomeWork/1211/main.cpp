#include <iostream>
#include <vector>

//task 1 start
class Matrix {
private:
    std::vector<std::vector<double>> m;
public:
    ~Matrix() {};
    Matrix() {};
    Matrix(size_t rows, size_t cols);
    Matrix(size_t n);
    static Matrix unit_matrix(size_t n) {
        Matrix unitMatrix(n);

        for (size_t i = 0; i < n; i++) {
            unitMatrix[i][i] = 1;
        }

        return unitMatrix;
    };
    static Matrix row_matrix(size_t n) { return Matrix(n, 1); };
    static Matrix col_matrix(size_t n) { return Matrix(1, n); };
    Matrix(const std::vector<double>& diag);
    Matrix(const Matrix& obj) {
        if (colSize() != 0) {
            for (size_t i = 0; i < rowSize(); i++) {
                m[i].clear();
            }
        }
        if (rowSize() != 0) {
            m.clear();
        }

        m.resize(obj.rowSize());
        if (rowSize() == 0) {
            return;
        }
        for (size_t i = 0; i < obj.rowSize(); i++) {
            m[i].resize(obj.colSize());
        }

        for (size_t i = 0; i < obj.rowSize(); i++) {
            for (size_t j = 0; j < obj.colSize(); j++) {
                m[i][j] = obj[i][j];
            }
        }
    };
    Matrix(Matrix&& obj);
    Matrix(const std::vector<std::vector<double>>& src);
    Matrix(std::vector<std::vector<double>>&& src);
    size_t rowSize() const;
    size_t colSize() const;
    size_t size() const;
    std::vector<double>& operator[](size_t row);
    const std::vector<double>& operator[](size_t row) const;
    Matrix& operator=(const Matrix& src);
    Matrix& operator=(Matrix&& src);
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;
    Matrix operator*(double mulltiplier) const;
    Matrix operator^(int power) const;
    friend Matrix operator*(double mulltiplier, const Matrix& obj);
    Matrix operator/(double divider) const;
    Matrix operator/(const Matrix& rhs) const;
    Matrix& operator+=(const Matrix& rhs);
    Matrix& operator-=(const Matrix& rhs);
    Matrix& operator*=(const Matrix& rhs);
    Matrix& operator*=(double mulltiplier);
    friend Matrix operator*=(double mulltiplier, Matrix& obj);
    Matrix operator/=(double divider);
    Matrix operator/=(const Matrix rhs);
    Matrix inverse();
    Matrix minor(size_t row, size_t col);
    double det();
    Matrix transpose() const;
};

Matrix::Matrix(size_t rows, size_t cols) {

    m.resize(rows);
    if (rows == 0) {
        return;
    }
    for (size_t i = 0; i < rows; i++) {
        m[i].resize(cols);
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            m[i][j] = 0;
        }
    }
}

Matrix::Matrix(size_t n) {

    m.resize(n);
    if (n == 0) {
        return;
    }
    for (size_t i = 0; i < n; i++) {
        m[i].resize(n);
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }
}

Matrix::Matrix(const std::vector<double>& diag) {

    m.resize(diag.size());
    for (size_t i = 0; i < diag.size(); i++) {
        m[i].resize(diag.size());
    }

    for (size_t i = 0; i < diag.size(); i++) {
        for (size_t j = 0; j < diag.size(); j++) {
            if (i == j) {
                m[i][j] = diag[i];
            }
            else {
                m[i][j] = 0;
            }
        }
    }
}

Matrix::Matrix(Matrix&& obj) {

    m.resize(obj.rowSize());
    for (size_t i = 0; i < obj.rowSize(); i++) {
        m[i].resize(obj.colSize());
    }
    for (size_t i = 0; i < obj.rowSize(); i++) {
        m[i] = obj[i];
    }
    for (size_t i = 0; i < obj.colSize(); i++) {
        obj.m[i].clear();
    }
    if (obj.rowSize() != 0) {
        obj.m.clear();
    }
}

Matrix::Matrix(const std::vector<std::vector<double>>& src) {

    m.resize(src.size());
    if (rowSize() == 0) {
        return;
    }
    for (size_t i = 0; i < src.size(); i++) {
        m[i].resize(src[0].size());
    }

    for (size_t i = 0; i < rowSize(); i++) {
        for (size_t j = 0; j < colSize(); j++) {
            m[i][j] = src[i][j];
        }
    }
}

Matrix::Matrix(std::vector<std::vector<double>>&& src) {

    if (colSize() != 0) {
        for (size_t i = 0; i < rowSize(); i++) {
            m[i].clear();
        }
    }
    if (rowSize() != 0) {
        m.clear();
    }

    m.resize(src.size());
    if (src[0].size() == 0) {
        return;
    }
    for (size_t i = 0; i < src.size(); i++) {
        m[i].resize(src[0].size());
    }

    for (size_t i = 0; i < rowSize(); i++) {
        for (size_t j = 0; j < colSize(); j++) {
            m[i][j] = src[i][j];
        }
    }
}

size_t Matrix::rowSize() const {
    return m.size();
}

size_t Matrix::colSize() const {
    if (rowSize() == 0) {
        return 0;
    }
    return m[0].size();
}

size_t Matrix::size() const {
    return rowSize() * colSize();
}

std::vector<double>& Matrix::operator[](size_t row) {
    return m[row];
}

const std::vector<double>& Matrix::operator[](size_t row) const {
    return m[row];
}

Matrix& Matrix::operator=(const Matrix& src) {

    if (this != &src) {

        if (src.rowSize() == 0) {
            throw std::invalid_argument("Error: Matrix is empty");
        }

        if (this->colSize() != 0) {
            for (size_t i = 0; i < this->rowSize(); i++) {
                this->m[i].clear();
            }
        }
        if (this->rowSize() != 0) {
            this->m.clear();
        }

        this->m.resize(src.rowSize());
        for (size_t i = 0; i < src.rowSize(); i++) {
            this->m[i].resize(src[0].size());
        }

        for (size_t i = 0; i < this->rowSize(); i++) {
            for (size_t j = 0; j < this->colSize(); j++) {
                this->m[i][j] = src[i][j];
            }
        }
    }

    return *this;
}

Matrix& Matrix::operator=(Matrix&& src) {

    if (this != &src) {

        if (src.rowSize() == 0) {
            throw std::invalid_argument("Error: Matrix is empty");
        }

        if (this->colSize() != 0) {
            for (size_t i = 0; i < this->rowSize(); i++) {
                this->m[i].clear();
            }
        }
        if (this->rowSize() != 0) {
            this->m.clear();
        }

        this->m.resize(src.rowSize());
        for (size_t i = 0; i < rowSize(); i++) {
            this->m[i].resize(src.colSize());
        }

        for (size_t i = 0; i < rowSize(); i++) {
            this->m[i] = src[i];
        }

        for (size_t i = 0; i < src[0].size(); i++) {
            src.m[i].clear();
        }
        src.m.clear();
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) const {

    if (this->rowSize() != rhs.rowSize() || this->colSize() != rhs.colSize()) {
        throw std::invalid_argument("Error: Matrix aren't of the same area");
    }

    Matrix tmp(*this);

    for (size_t i = 0; i < rowSize(); i++) {
        for (size_t j = 0; j < colSize(); j++) {
            tmp.m[i][j] = m[i][j] + rhs[i][j];
        }
    }

    return tmp;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (this->rowSize() != rhs.rowSize() || this->colSize() != rhs.colSize()) {
        throw std::invalid_argument("Error: Matrix aren't of the same area");
    }

    Matrix tmp(*this);

    for (size_t i = 0; i < rowSize(); i++) {
        for (size_t j = 0; j < colSize(); j++) {
            tmp.m[i][j] = m[i][j] - rhs[i][j];
        }
    }

    return tmp;
}

Matrix Matrix::operator*(const Matrix& rhs) const {

    if (this->colSize() != rhs.rowSize()) {
        throw std::invalid_argument("Error: Matrix aren't consistent");
    }

    Matrix tmp(this->rowSize(), rhs.colSize());

    for (size_t i = 0; i < tmp.rowSize(); i++) {
        for (size_t j = 0; j < tmp.colSize(); j++) {
            for (size_t k = 0; k < this->colSize(); k++) {
                tmp[i][j] += this->m[i][k] * rhs[k][j];
            }
        }
    }

    return tmp;
}

Matrix Matrix::operator*(double mulltiplier) const {

    Matrix tmp(*this);

    for (size_t i = 0; i < tmp.rowSize(); i++) {
        for (size_t j = 0; j < tmp.colSize(); j++) {
            tmp[i][j] = tmp[i][j] * mulltiplier;
        }
    }

    return tmp;
}

Matrix Matrix::operator^(int power) const {

    if (this->rowSize() != this->colSize()) {
        throw std::invalid_argument("Error: Only squre matrix can be raised to a power");
    }

    Matrix tmp = *this;
    if (power == 0) {
        tmp = this->unit_matrix(tmp.rowSize());
    }
    else if (power > 0) {
        Matrix originalMatrix(*this);
        for (size_t i = 1; i < power; i++) {
            tmp *= originalMatrix;
        }
    }
    else {
        Matrix tmpInverse = tmp.inverse();
        tmp = tmpInverse;
        for (size_t i = -1; i > power; i--) {
            tmp *= tmpInverse;
        }
    }
    return tmp;
}

Matrix Matrix::operator/(double divider) const {

    Matrix tmp(*this);

    for (size_t i = 0; i < tmp.rowSize(); i++) {
        for (size_t j = 0; j < tmp.colSize(); j++) {
            tmp[i][j] = tmp[i][j] / divider;
        }
    }

    return tmp;
}

Matrix Matrix::operator/(const Matrix& rhs) const {

    Matrix tmp(*this);
    Matrix tmp2(rhs);
    Matrix rhsInverse = tmp2.inverse();

    for (size_t i = 0; i < tmp2.rowSize(); i++) {
        tmp2.m[i].clear();
    }
    tmp2.m.clear();

    tmp *= rhsInverse;

    return tmp;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {

    if (this->rowSize() != rhs.rowSize() || this->colSize() != rhs.colSize()) {
        throw std::invalid_argument("Error: Matrix aren't of the same area");
    }

    for (size_t i = 0; i < this->rowSize(); i++) {
        for (size_t j = 0; j < this->colSize(); j++) {
            this->m[i][j] += rhs[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs) {
    if (this->rowSize() != rhs.rowSize() || this->colSize() != rhs.colSize()) {
        throw std::invalid_argument("Error: Matrix aren't of the same area");
    }

    for (size_t i = 0; i < this->rowSize(); i++) {
        for (size_t j = 0; j < this->colSize(); j++) {
            this->m[i][j] -= rhs[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs) {

    if (this->colSize() != rhs.rowSize()) {
        throw std::invalid_argument("Error: Matrix aren't consistent");
    }

    Matrix tmp(this->rowSize(), rhs.colSize());

    for (size_t i = 0; i < tmp.rowSize(); i++) {
        for (size_t j = 0; j < rhs.colSize(); j++) {
            for (size_t k = 0; k < this->colSize(); k++) {
                tmp[i][j] += this->m[i][k] * rhs[k][j];
            }
        }
    }

    this->m = tmp.m;

    return *this;
}

Matrix& Matrix::operator*=(double mulltiplier) {

    for (size_t i = 0; i < this->rowSize(); i++) {
        for (size_t j = 0; j < this->colSize(); j++) {
            this->m[i][j] *= mulltiplier;
        }
    }

    return *this;
}

Matrix Matrix::operator/=(double divider) {

    for (size_t i = 0; i < this->rowSize(); i++) {
        for (size_t j = 0; j < this->colSize(); j++) {
            this->m[i][j] /= divider;
        }
    }

    return *this;
}

Matrix Matrix::operator/=(const Matrix rhs) {

    Matrix tmp(*this);
    Matrix tmp2(rhs);
    Matrix rhsInverse = tmp2.inverse();

    for (size_t i = 0; i < tmp2.rowSize(); i++) {
        tmp2.m[i].clear();
    }
    tmp2.m.clear();

    tmp *= rhsInverse;

    this->m = tmp.m;

    return tmp;
}

Matrix Matrix::inverse() {

    if (this->rowSize() != this->colSize()) {
        throw std::invalid_argument("Error: Matrix must be square");
    }

    double determinant = this->det();
    if (determinant == 0) {
        throw std::invalid_argument("Error: Matrix is singular, cann't be inversed");
    }

    Matrix inverseMatrix(this->rowSize());

    for (size_t i = 0; i < this->rowSize(); i++) {
        for (size_t j = 0; j < this->colSize(); j++) {
            Matrix minorMatrix(*this);
            inverseMatrix[i][j] = std::pow(-1, i + j) * minorMatrix.minor(i, j).det();
        }
    }

    Matrix tmp = inverseMatrix.transpose();

    tmp /= determinant;

    this->m = tmp.m;

    return *this;
}

Matrix Matrix::minor(size_t row, size_t col) {

    Matrix tmp(this->rowSize() - 1, this->colSize() - 1);

    for (size_t i = 0, mi = 0; i < this->rowSize(); i++) {
        if (i == row) {
            continue;
        }
        else {
            for (size_t j = 0, mj = 0; j < this->colSize(); j++) {
                if (j == col) {
                    continue;
                }
                else {
                    tmp[mi][mj] = this->m[i][j];
                    mj++;
                }
            }
            mi++;
        }
    }

    this->m = tmp.m;

    return *this;
}

double Matrix::det() {

    if (this->rowSize() != this->colSize()) {
        throw std::invalid_argument("Error: determinant can only be calculated for a squre matrix");
    }

    if (this->rowSize() == 0) {
        return 1.0;
    }
    if (this->rowSize() == 1) {
        return this->m[0][0];
    }
    if (this->rowSize() == 2) {
        return this->m[0][0] * this->m[1][1] - this->m[1][0] * this->m[0][1];
    }

    double d = 0.0;

    for (size_t j = 0; j < this->colSize(); j++) {
        Matrix minorMatrix(*this);
        d += std::pow(-1, j) * this->m[0][j] * minorMatrix.minor(0, j).det();
    }

    return d;
}

Matrix Matrix::transpose() const {

    Matrix tmp(this->colSize(), this->rowSize());

    for (size_t i = 0; i < tmp.rowSize(); i++) {
        for (size_t j = 0; j < tmp.colSize(); j++) {
            tmp[i][j] = this->m[j][i];
        }
    }

    return tmp;
}

Matrix operator*(double mulltiplier, const Matrix& obj) {

    Matrix tmp(obj);

    for (size_t i = 0; i < tmp.rowSize(); i++) {
        for (size_t j = 0; j < tmp.colSize(); j++) {
            tmp[i][j] = tmp[i][j] * mulltiplier;
        }
    }

    return tmp;
}

Matrix operator*=(double mulltiplier, Matrix& obj) {

    for (size_t i = 0; i < obj.rowSize(); i++) {
        for (size_t j = 0; j < obj.colSize(); j++) {
            obj[i][j] *= mulltiplier;
        }
    }

    return obj;
}
// end task 1

int main() {

    Matrix m(3, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 1;
    m[1][1] = 1;
    m[1][2] = 1;
    m[2][0] = 4;
    m[2][1] = 5;
    m[2][2] = 2;

    /*for (size_t i = 0; i < m.rowSize(); i++) {
        for (size_t j = 0; j < m.colSize(); j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    double x = 5;

    x = x / x;

    Matrix m2 = m ^ -1;
    m /= m;
    //m2.inverse();

    for (size_t i = 0; i < m.rowSize(); i++) {
        for (size_t j = 0; j < m.colSize(); j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //m *= m2;

    for (size_t i = 0; i < m2.rowSize(); i++) {
        for (size_t j = 0; j < m2.colSize(); j++) {
            std::cout << m2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*Matrix m2(3, 2);
    m2[0][0] = 7;
    m2[0][1] = 8;
    m2[1][0] = 9;
    m2[1][1] = 10;
    m2[2][0] = 11;
    m2[2][1] = 12;*/

    //Matrix mat = m.transpose();
    //2 *= m;

    //Matrix mat_power = m ^ 2;
    //mat[6][3] = 45;

    //std::cout << mat[6][3] << std::endl;
    /*Matrix m3 = m.minor(0,3);

    for (size_t i = 0; i < m3.rowSize(); i++) {
        for (size_t j = 0; j < m3.colSize(); j++) {
            std::cout << m3[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    //std::cout << m.det() << std::endl;



    /*for (size_t i = 0; i < mat.rowSize(); i++) {
        for (size_t j = 0; j < mat.colSize(); j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    return 0;
}


