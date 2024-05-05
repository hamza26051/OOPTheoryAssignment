#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>

using namespace std;

template<typename T>
class Matrix {
protected:
    vector<vector<T>> matrix;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows,vector<T>(cols));
    }

    
    T get(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
           cout<<"out of range"<<endl;
            exit(1);
        }
        return matrix[row][col];
    }

    void set(int row, int col, T value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout<<"out of range"<<endl;
            exit(1);
        }
        matrix[row][col] = value;
    }

    virtual void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << "\t";
            }
            cout <<endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout<<"Dimensions mismatch!"<<endl;
            exit(1);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
           cout<<"Dimensions mismatch!"<<endl;
            exit(1);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            cout<<"Dimensions mismatch for multiplication!"<<endl;
            exit(1);
        }

        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
};

class IntMatrix : public Matrix<int> {
public:
    IntMatrix(int rows, int cols) : Matrix<int>(rows, cols) {}

    void display() const override {
        Matrix<int>::display();
    }
};

class DoubleMatrix : public Matrix<double> {
public:
    DoubleMatrix(int rows, int cols) : Matrix<double>(rows, cols) {}

    void display() const override {
        Matrix<double>::display();
    }
};

int main() {
    IntMatrix intMatrix1(2, 2);
    intMatrix1.set(0, 0, 1);
    intMatrix1.set(0, 1, 2);
    intMatrix1.set(1, 0, 3);
    intMatrix1.set(1, 1, 4);

    IntMatrix intMatrix2(2, 2);
    intMatrix2.set(0, 0, 5);
    intMatrix2.set(0, 1, 6);
    intMatrix2.set(1, 0, 7);
    intMatrix2.set(1, 1, 8);

    Matrix<int> intResultAdd = intMatrix1 + intMatrix2;
    cout << "Integer Matrix Addition Result:" << endl;
    intResultAdd.display();
    cout << endl;

    Matrix<int> intResultSub = intMatrix1 - intMatrix2;
    cout << "Integer Matrix Subtraction Result:" << endl;
    intResultSub.display();
    cout << endl;

    Matrix<int> intResultMul = intMatrix1 * intMatrix2;
    cout << "Integer Matrix Multiplication Result:" << endl;
    intResultMul.display();
    cout << endl;

    DoubleMatrix doubleMatrix1(2, 2);
    doubleMatrix1.set(0, 0, 1.5);
    doubleMatrix1.set(0, 1, 2.5);
    doubleMatrix1.set(1, 0, 3.5);
    doubleMatrix1.set(1, 1, 4.5);

    DoubleMatrix doubleMatrix2(2, 2);
    doubleMatrix2.set(0, 0, 5.5);
    doubleMatrix2.set(0, 1, 6.5);
    doubleMatrix2.set(1, 0, 7.5);
    doubleMatrix2.set(1, 1, 8.5);

    Matrix<double> doubleResultAdd = doubleMatrix1 + doubleMatrix2;
    cout << "Double Matrix Addition Result:" << endl;
    doubleResultAdd.display();
    cout << endl;

    Matrix<double> doubleResultSub = doubleMatrix1 - doubleMatrix2;
    cout << "Double Matrix Subtraction Result:" << endl;
    doubleResultSub.display();
    cout << endl;

    Matrix<double> doubleResultMul = doubleMatrix1 * doubleMatrix2;
    cout << "Double Matrix Multiplication Result:" << endl;
    doubleResultMul.display();
    cout << endl;

    return 0;
}

