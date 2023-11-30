
#include <iostream>

using namespace std;

class Matrix {
private:
    int x11, x12, x21, x22 = x22;

public:
    Matrix(int a11, int a12, int a21, int a22) : x11(a11), x12(a12), x21(a21), x22(a22) {}

    Matrix operator+(const Matrix& other) const {
        return Matrix(x11 + other.x11, x12 + other.x12,
                      x21 + other.x21, x22 + other.x22);
    }

    Matrix operator-(const Matrix& other) const {
        return Matrix(x11 - other.x11, x12 - other.x12,
                      x21 - other.x21, x22 - other.x22);
    }

    Matrix operator*(const Matrix& other) const {
        return Matrix(x11 * other.x11 + x12 * other.x21, x11 * other.x12 + x12 * other.x22,
                      x21 * other.x11 + x22 * other.x21, x21 * other.x12 + x22 * other.x22);
    }

    friend ostream& operator<<(ostream& os, const Matrix& m) {
        os << "[" << m.x11 << " " << m.x12 << "]\n"
           << "[" << m.x21 << " " << m.x22 << "]";
        return os;
    }
};

int main() {
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);

    Matrix sum = m1 + m2;
    Matrix diff = m1 - m2;
    Matrix prod = m1 * m2;

    cout << "First matrix:\n" << m1 << endl;
    cout << "\nSecond matrix:\n" << m2 << endl;
    cout << "\nSum of the first and second matrices:\n" << sum << endl;
    cout << "\nDifference between the first and second matrices:\n" << diff << endl;
    cout << "\nProduct of the first and second matrices:\n" << prod << endl;

    return 0;
}
